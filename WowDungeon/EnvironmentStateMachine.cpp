#pragma once
#include "pch.h"
#include "EnvironmentStateMachine.h"


namespace WowDungeon
{
	EnvironmentStateMachine::EnvironmentStateMachine(shared_ptr<string> command)
	{
		SetCommandString(command);
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
		auto enterRoom1 = make_shared<DisplayTextAction>("You enter room 1.  You see a door to the north and the south.");
		auto enterRoom2 = make_shared<DisplayTextAction>("You enter room 2.  You see a door to the west, east, and the south.");
		auto enterRoom3 = make_shared<DisplayTextAction>("You enter room 3.  You see a door to the west.");
		auto enterRoom4 = make_shared<DisplayTextAction>("You enter room 4.  You see a door to the east and the south.");
		auto enterRoom5 = make_shared<DisplayTextAction>("You enter room 5.  You see a door to the north and the south");
		auto enterRoom6 = make_shared<DisplayTextAction>("You enter room 6.  You see a door to the north and to the east.");
		auto enterRoom7 = make_shared<DisplayTextAction>("You enter room 7.  You see a door to the west, north, and east.");
		auto enterRoom8 = make_shared<DisplayTextAction>("You enter room 8.  You see a door to the west and the south.");
		auto enterRoom9 = make_shared<DisplayTextAction>("You enter room 9.  You see a door to the north.");
		auto exitRoom = make_shared<DisplayTextAction>("You boldy enter the next room.");

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
		room9->AddTransition(room9to8);

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