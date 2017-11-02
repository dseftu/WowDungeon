#include "pch.h"
#include "Condition.h"
#include "EqualityCondition.h"
#include "StringEqualityCondition.h"
#include "DisplayTextAction.h"
#include "State.h"
#include "Action.h"
#include "Transition.h"
#include <string>

using namespace std;
using namespace WowDungeon;

int main()
{
	shared_ptr<string> command = make_unique<string>();
	
	// create the predefined conditions
	shared_ptr<Condition> ConditionGoNorth = make_shared<StringEqualityCondition>(make_shared<string>("north"), command);
	shared_ptr<Condition> ConditionGoSouth = make_shared<StringEqualityCondition>(make_shared<string>("south"), command);
	shared_ptr<Condition> ConditionGoEast = make_shared<StringEqualityCondition>(make_shared<string>("east"), command);
	shared_ptr<Condition> ConditionGoWest = make_shared<StringEqualityCondition>(make_shared<string>("west"), command);

	// create some enter and exit transitions
	auto enterRoom1 = make_shared<DisplayTextAction>("You enter room 1.  You see a door to the north");
	auto enterRoom2 = make_shared<DisplayTextAction>("You enter room 2.  You see a door to the west, east, and the south.");
	auto enterRoom3 = make_shared<DisplayTextAction>("You enter room 3.  You see a door to the west.");
	auto enterRoom4 = make_shared<DisplayTextAction>("You enter room 4.  You see a door to the east and the south.");
	auto enterRoom5 = make_shared<DisplayTextAction>("You enter room 5.  You see a door to the north.");
	auto exitRoom = make_shared<DisplayTextAction>("You boldy enter the next room.");

	// create some states
	shared_ptr<State> room1 = make_shared<State>("Room1", enterRoom1, exitRoom);
	shared_ptr<State> room2 = make_shared<State>("Room2", enterRoom2, exitRoom);
	shared_ptr<State> room3 = make_shared<State>("Room3", enterRoom3, exitRoom);
	shared_ptr<State> room4 = make_shared<State>("Room4", enterRoom4, exitRoom);
	shared_ptr<State> room5 = make_shared<State>("Room5", enterRoom5, exitRoom);

	// add transitions
	auto room1to2 = make_shared<Transition>(ConditionGoNorth, room2);
	
	auto room2to1 = make_shared<Transition>(ConditionGoSouth, room1);
	auto room2to3 = make_shared<Transition>(ConditionGoEast, room3);
	auto room2to4 = make_shared<Transition>(ConditionGoWest, room4);

	auto room3to2 = make_shared<Transition>(ConditionGoWest, room2);
	
	auto room4to2 = make_shared<Transition>(ConditionGoEast, room2);
	auto room4to5 = make_shared<Transition>(ConditionGoSouth, room5);

	auto room5to4 = make_shared<Transition>(ConditionGoNorth, room4);

	room1->AddTransition(room1to2);
	room2->AddTransition(room2to1);
	room2->AddTransition(room2to3);
	room2->AddTransition(room2to4);
	room3->AddTransition(room3to2);
	room4->AddTransition(room4to2);
	room4->AddTransition(room4to5);
	room5->AddTransition(room5to4);

	auto currentRoom = room1;
	currentRoom->Enter();

	while (true)
	{
		cout << "> ";

		cin >> *command;
		auto stateCheck = currentRoom->Update();
		if (stateCheck != nullptr)
		{
			currentRoom = stateCheck;
		}

	}
	return 0;
}