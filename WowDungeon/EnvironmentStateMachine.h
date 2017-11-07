#pragma once
#include <memory>
#include "StateMachine.h"
#include "State.h"
#include "Condition.h"
#include "Transition.h"
#include "StringEqualityCondition.h"
#include "DisplayTextAction.h"
#include "Blackboard.h"
#include "ActionList.h"
#include "EndGameAction.h"
#include "RandomAction.h"
namespace WowDungeon
{
	using namespace std;

	class EnvironmentStateMachine :
		public StateMachine
	{
	public:
		EnvironmentStateMachine() = delete;
		EnvironmentStateMachine(shared_ptr<Blackboard> blackboard);
		virtual void Initialize() override;
		
		const string GetPlayerCurrentRoom();
		void SetCommandString(shared_ptr<string> command) { mCommand = command; };
	private:
		shared_ptr<Blackboard> mBlackboard;
		shared_ptr<string> mCommand;
	};

}
