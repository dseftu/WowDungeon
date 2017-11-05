#include "pch.h"
#include <string>
#include "EnvironmentStateMachine.h"
#include "Blackboard.h"

using namespace std;
using namespace WowDungeon;

int main()
{	
	shared_ptr<string> command = make_unique<string>();
	shared_ptr<Blackboard> blackboard = make_shared<Blackboard>(command);

	shared_ptr<EnvironmentStateMachine> environment = make_shared<EnvironmentStateMachine>();
	environment->Initialize(command);
	
	// main game update loop
	while (true)
	{
		cout << "> ";

		cin >> *command;

		environment->Update();		
		blackboard->SetPlayerCurrentRoom(environment->CurrentState()->Name());
		blackboard->UpdatePlayerLastDirection();
		
	}
	return 0;
}