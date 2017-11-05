#pragma once
#include <memory>
#include <string>
#include "StateMachine.h"
#include "State.h"
#include "Condition.h"
#include "Transition.h"
#include "StringEqualityCondition.h"
#include "DisplayTextAction.h"
#include "Blackboard.h"
#include "EnvironmentStateMachine.h"
#include "SameRoomAsPlayerCondition.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "EndGameAction.h"
#include "ActionList.h"
namespace WowDungeon
{
	class MonsterStateMachine :
		public StateMachine
	{
	public:
		MonsterStateMachine() = default;
		MonsterStateMachine(shared_ptr<Blackboard> blackboard, shared_ptr<EnvironmentStateMachine> environment);
		virtual void Initialize() override;
		const string GetMonsterCurrentRoom() { return mMonsterCurrentRoom; };

	private:
		shared_ptr<Blackboard> mBlackboard;
		shared_ptr<EnvironmentStateMachine> mEnvironment;
		string mMonsterCurrentRoom = "Room1";
		map<string, shared_ptr<State>> rooms;


	};

}
