#pragma once
#include <memory>
#include "Condition.h"
#include "MonsterStateMachine.h"
#include "EnvironmentStateMachine.h"


namespace WowDungeon
{
	class MonsterStateMachine;

	class SameRoomAsPlayerCondition :
		public Condition
	{
	public:
		SameRoomAsPlayerCondition() = delete;
		SameRoomAsPlayerCondition(shared_ptr<EnvironmentStateMachine> environment, shared_ptr<MonsterStateMachine> monsterStateMachine);
		
		// Inherited via Condition
		virtual bool Evaluate() override;

	private:
		shared_ptr<MonsterStateMachine> mMonsterStateMachine;
		shared_ptr<EnvironmentStateMachine> mEnvironment;
	};
}

