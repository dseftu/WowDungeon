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

		srand((unsigned int)time(0));

		while (mMonsterCurrentRoom == "Room1")
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
		shared_ptr<Condition> SameRoomAsPlayer = make_shared<SameRoomAsPlayerCondition>(mEnvironment, currentMachine);


		auto cheatMode = make_shared<DisplayTextAction>("The monster is in " + mMonsterCurrentRoom);
		auto emptyText = make_shared<DisplayTextAction>("");
		auto foundCreature = make_shared<DisplayTextAction>("Wow!  The creature is lurking in this room.  Make your escape!");
		auto feelingSafe = make_shared<DisplayTextAction>("You feel safe.");
		auto death = make_shared<DisplayTextAction>("The creature has caught you!");
		auto endGame = make_shared<EndGameAction>(mBlackboard);
		auto endGameActions = make_shared<ActionList>();
		endGameActions->AddAction(death);
		endGameActions->AddAction(endGame);


		shared_ptr<State> idle = make_shared<State>("Idle", cheatMode, emptyText);
		shared_ptr<State> chase = make_shared<State>("Chase", foundCreature, emptyText);
		shared_ptr<State> caught = make_shared<State>("Caught", endGameActions, emptyText);

		auto idleToChase = make_shared<Transition>(SameRoomAsPlayer, chase);		
		idle->AddTransition(idleToChase);

		auto chaseToCaught = make_shared<Transition>(SameRoomAsPlayer, caught);
		chase->AddTransition(chaseToCaught);


		SetCurrentState(idle);
		idle->Enter();

	}

}