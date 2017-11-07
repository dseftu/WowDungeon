#pragma once
#include "pch.h"
#include "MonsterStateMachine.h"


namespace WowDungeon
{

	MonsterStateMachine::MonsterStateMachine(shared_ptr<Blackboard> blackboard, shared_ptr<EnvironmentStateMachine> environment)
	{
		mBlackboard = blackboard;
		mEnvironment = environment;

		Initialize();
	}

	void MonsterStateMachine::Initialize()
	{
		// pick a room for the monster to be in
		rooms = mEnvironment->States();
		while (mMonsterCurrentRoom == "Room1" && mMonsterCurrentRoom != "LastRoom")
		{
			auto nextRand = rand();
			auto numRooms = rooms.size();
			int32_t next = nextRand % numRooms;

			for (auto i = rooms.begin(); i != rooms.end(); ++i)
			{
				if (next-- == 0) mMonsterCurrentRoom = i->second->Name();
			}
		}
		

		shared_ptr<MonsterStateMachine> currentMachine = make_shared<MonsterStateMachine>(*this);
		shared_ptr<Condition> sameRoomAsPlayer = make_shared<SameRoomAsPlayerCondition>(mEnvironment, currentMachine);
		shared_ptr<Condition> notSameRoomAsPlayer = make_shared<NotCondition>(sameRoomAsPlayer);
		shared_ptr<Condition> alwaysTrue = make_shared<EqualityCondition<bool>>(true, true);

		auto emptyText = make_shared<DisplayTextAction>("");
		auto foundCreature = make_shared<DisplayTextAction>("Wow!  The creature is lurking in this room.  Make your escape!");
		auto creatureFollows = make_shared<DisplayTextAction>("The creature follows behind you!");
		auto feelingSafe = make_shared<DisplayTextAction>("You feel safe.");
		auto death = make_shared<DisplayTextAction>("The creature has caught you!");
		auto followPlayer = make_shared<MonsterChaseAction>(mEnvironment, currentMachine);
		auto followPlayerActions = make_shared<ActionList>();
		followPlayerActions->AddAction(followPlayer);
		followPlayerActions->AddAction(creatureFollows);
		auto endGame = make_shared<EndGameAction>(mBlackboard);
		auto endGameActions = make_shared<ActionList>();
		endGameActions->AddAction(death);
		endGameActions->AddAction(endGame);

		// state when the monster feels safe.
		shared_ptr<State> idle = make_shared<State>("Idle", feelingSafe, emptyText);

		// state after spotting the player, and attempts to chase them
		shared_ptr<State> found = make_shared<State>("Found", foundCreature, emptyText);
		shared_ptr<State> chase = make_shared<State>("Chase", followPlayerActions, emptyText);

		// state to transition to should the monster catch the player
		shared_ptr<State> caught = make_shared<State>("Caught", endGameActions, emptyText);

		auto idleToFound = make_shared<Transition>(sameRoomAsPlayer, found);
		idle->AddTransition(idleToFound);

		auto foundToCaught = make_shared<Transition>(sameRoomAsPlayer, caught);
		found->AddTransition(foundToCaught);

		auto foundToChase = make_shared<Transition>(notSameRoomAsPlayer, chase);
		found->AddTransition(foundToChase);

		auto chaseToIdle = make_shared<Transition>(notSameRoomAsPlayer, idle);
		chase->AddTransition(chaseToIdle);

		auto chaseToCaught = make_shared<Transition>(sameRoomAsPlayer, caught);
		chase->AddTransition(chaseToCaught);


		SetCurrentState(idle);
		idle->Enter();

	}

}