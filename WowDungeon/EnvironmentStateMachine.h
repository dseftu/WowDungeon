#pragma once
#include <memory>
#include "StateMachine.h"
#include "State.h"
#include "Condition.h"
#include "Transition.h"
#include "StringEqualityCondition.h"
#include "DisplayTextAction.h"


namespace WowDungeon
{
	using namespace std;

	class EnvironmentStateMachine :
		public StateMachine
	{
	public:

		virtual void Initialize() override;
		void Initialize(shared_ptr<string> command);

		void SetCommandString(shared_ptr<string> command) { mCommand = command; };

	private:
		shared_ptr<string> mCommand;
	};

}
