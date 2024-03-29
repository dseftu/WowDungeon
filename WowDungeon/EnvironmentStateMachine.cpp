#pragma once
#include "pch.h"
#include "EnvironmentStateMachine.h"


namespace WowDungeon
{
	EnvironmentStateMachine::EnvironmentStateMachine(shared_ptr<Blackboard> blackboard)
	{
		mBlackboard = blackboard;
		SetCommandString(mBlackboard->GetCommandString());
		Initialize();
	}
	void EnvironmentStateMachine::Initialize()
	{
		// command must be set
		assert(mCommand != nullptr);

		// create the predefined conditions
		shared_ptr<Condition> ConditionGoNorth = make_shared<StringEqualityCondition>(make_shared<string>("north"), mCommand);
		shared_ptr<Condition> ConditionGoSouth = make_shared<StringEqualityCondition>(make_shared<string>("south"), mCommand);
		shared_ptr<Condition> ConditionGoEast = make_shared<StringEqualityCondition>(make_shared<string>("east"), mCommand);
		shared_ptr<Condition> ConditionGoWest = make_shared<StringEqualityCondition>(make_shared<string>("west"), mCommand);

		// create some enter and exit transitions
		auto enterRoom1 = make_shared<DisplayTextAction>("The room you are standing in is barren.\nYou see a door to the north and the south.");
		auto enterRoom2 = make_shared<DisplayTextAction>("You stumble into the next room.  There are torches on the walls illuminating the room.\nYou see a door to the west, east, and the south.");
		auto enterRoom3 = make_shared<DisplayTextAction>("You enter the room and realize this was a dead end.  On the bright side, there is a small window in here.  It looks nice outside, exactly where you aren't.  Oh well.\nYou see a door to the west.");
		auto enterRoom4 = make_shared<DisplayTextAction>("Entering the room, you notice an elaborate tapastry adorning the west wall.  It seems to be depicting a great battle, presumably one that the previous owner participated in.  You recognize the colors of the armies on the field as those of the neighboring kingdom.  This probably would be very interesting to someone who gets excited over putting rugs on the wall.\nYou see a door to the east and the south.");
		auto enterRoom5 = make_shared<DisplayTextAction>("You notice a large chandeler in the middle of this hallway.  It is adorned with several very large rubys.\nYou see a door to the north and the south");
		auto enterRoom6 = make_shared<DisplayTextAction>("The corner of this room has a small, damaged chair.  You don't dare sit on it.\nYou see a door to the north and to the east.");
		auto enterRoom7 = make_shared<DisplayTextAction>("You enter a room with three doors.\nYou see a door to the west, north, and east.");
		auto enterRoom8 = make_shared<DisplayTextAction>("This room is brighter than the rest.  You think you might be close to an exit.\nYou see a door to the west and the south.");
		auto enterRoom9 = make_shared<DisplayTextAction>("At last you see the exit!\nYou see a door to the north and the dungeon exit to the south.");
		auto exitRoom = make_shared<DisplayTextAction>("\nYou leave the room.\n");

		// good intentions, didn't have time.
		/*
		auto invalidMove1 = make_shared<DisplayTextAction>("You bounce against the wall.  This doesn't seem to be your day.");
		auto invalidMove2 = make_shared<DisplayTextAction>("You triumphantly attempt to walk through a wall.  This does not go well.");
		auto invalidMove3 = make_shared<DisplayTextAction>("You start to concentrate, and attempt to create a hole in the wall with your mind powers.  Unfortunately, you do not have mind powers.");
		auto invalidMove4 = make_shared<DisplayTextAction>("You search around the wall for a hidden lever.  You don't find any.");
		auto invalidMove5 = make_shared<DisplayTextAction>("Hitting your head against the wall doesn't seem to help anything.");
		auto invalidMove6 = make_shared<DisplayTextAction>("You attempt to open the wall like a door.  It opens exactly the way that doors don't.");
		auto invalidMoves = make_shared<RandomAction>();
		invalidMoves->AddAction(invalidMove1);
		invalidMoves->AddAction(invalidMove2);
		invalidMoves->AddAction(invalidMove3);
		invalidMoves->AddAction(invalidMove4);
		invalidMoves->AddAction(invalidMove5);
		invalidMoves->AddAction(invalidMove6);
		*/

		auto emptyText = make_shared<DisplayTextAction>("");
		auto leaveDungeon = make_shared<DisplayTextAction>("You have successfully escaped the dungeon!");
		auto endGame = make_shared<EndGameAction>(mBlackboard);
		auto endGameActions = make_shared<ActionList>();
		endGameActions->AddAction(leaveDungeon);
		endGameActions->AddAction(endGame);

		// create some states
		shared_ptr<State> room1 = make_shared<State>("Room1", enterRoom1, exitRoom);
		shared_ptr<State> room2 = make_shared<State>("Room2", enterRoom2, exitRoom);
		shared_ptr<State> room3 = make_shared<State>("Room3", enterRoom3, exitRoom);
		shared_ptr<State> room4 = make_shared<State>("Room4", enterRoom4, exitRoom);
		shared_ptr<State> room5 = make_shared<State>("Room5", enterRoom5, exitRoom);
		shared_ptr<State> room6 = make_shared<State>("Room6", enterRoom6, exitRoom);
		shared_ptr<State> room7 = make_shared<State>("Room7", enterRoom7, exitRoom);
		shared_ptr<State> room8 = make_shared<State>("Room8", enterRoom8, exitRoom);
		shared_ptr<State> room9 = make_shared<State>("Room9", enterRoom9, exitRoom);
		shared_ptr<State> lastRoom = make_shared<State>("LastRoom", endGameActions, emptyText);
		
		// add transitions
		auto room1to2 = make_shared<Transition>(ConditionGoNorth, room2);
		auto room1to7 = make_shared<Transition>(ConditionGoSouth, room7);
		room1->AddTransition(room1to2);
		room1->AddTransition(room1to7);

		auto room2to1 = make_shared<Transition>(ConditionGoSouth, room1);
		auto room2to3 = make_shared<Transition>(ConditionGoEast, room3);
		auto room2to4 = make_shared<Transition>(ConditionGoWest, room4);
		room2->AddTransition(room2to1);
		room2->AddTransition(room2to3);
		room2->AddTransition(room2to4);

		auto room3to2 = make_shared<Transition>(ConditionGoWest, room2);
		room3->AddTransition(room3to2);

		auto room4to2 = make_shared<Transition>(ConditionGoEast, room2);
		auto room4to5 = make_shared<Transition>(ConditionGoSouth, room5);
		room4->AddTransition(room4to2);
		room4->AddTransition(room4to5);

		auto room5to4 = make_shared<Transition>(ConditionGoNorth, room4);
		auto room5to6 = make_shared<Transition>(ConditionGoSouth, room6);
		room5->AddTransition(room5to4);
		room5->AddTransition(room5to6);

		auto room6to5 = make_shared<Transition>(ConditionGoNorth, room5);
		auto room6to7 = make_shared<Transition>(ConditionGoEast, room7);
		room6->AddTransition(room6to5);
		room6->AddTransition(room6to7);

		auto room7to6 = make_shared<Transition>(ConditionGoWest, room6);
		auto room7to1 = make_shared<Transition>(ConditionGoNorth, room1);
		auto room7to8 = make_shared<Transition>(ConditionGoEast, room8);
		room7->AddTransition(room7to6);
		room7->AddTransition(room7to1);
		room7->AddTransition(room7to8);

		auto room8to7 = make_shared<Transition>(ConditionGoWest, room7);
		auto room8to9 = make_shared<Transition>(ConditionGoSouth, room9);
		room8->AddTransition(room8to7);
		room8->AddTransition(room8to9);

		auto room9to8 = make_shared<Transition>(ConditionGoNorth, room8);
		auto room9toExit = make_shared<Transition>(ConditionGoSouth, lastRoom);
		room9->AddTransition(room9to8);
		room9->AddTransition(room9toExit);

		AddState(room1);
		AddState(room2);
		AddState(room3);
		AddState(room4);
		AddState(room5);
		AddState(room6);
		AddState(room7);
		AddState(room8);
		AddState(room9);

		SetCurrentState(room1);
		room1->Enter();
	}

	const string EnvironmentStateMachine::GetPlayerCurrentRoom()
	{
		return CurrentState()->Name();
	}
	
}