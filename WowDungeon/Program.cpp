#include "pch.h"
#include <string>
#include "EnvironmentStateMachine.h"
#include "Blackboard.h"
#include "MonsterStateMachine.h"

using namespace std;
using namespace WowDungeon;

int main()
{	
	shared_ptr<string> command = make_unique<string>();
	shared_ptr<Blackboard> blackboard = make_shared<Blackboard>(command);

	shared_ptr<EnvironmentStateMachine> environment = make_shared<EnvironmentStateMachine>(blackboard);
	shared_ptr<MonsterStateMachine> monster = make_shared<MonsterStateMachine>(blackboard, environment);

	
	// main game update loop
	while (blackboard->Continue())
	{
		cout << "> ";

		cin >> *command;

		environment->Update();		
		blackboard->SetPlayerCurrentRoom(environment->GetPlayerCurrentRoom());
		blackboard->UpdatePlayerLastDirection();
		monster->Update();
		
	}

	cout << "Game over!" << endl;
	cin >> *command;

	return 0;
}