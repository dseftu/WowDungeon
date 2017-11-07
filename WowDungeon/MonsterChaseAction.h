#pragma once
#include "Action.h"
#include "EnvironmentStateMachine.h"
#include "MonsterStateMachine.h"


namespace WowDungeon
{
	class MonsterStateMachine;

	class MonsterChaseAction :
		public Action
	{
	public:
		MonsterChaseAction() = delete;
		MonsterChaseAction(shared_ptr<EnvironmentStateMachine> environment, shared_ptr<MonsterStateMachine> monsterStateMachine);	
		

		// Inherited via Action
		virtual void Do() override;

	private:
		shared_ptr<EnvironmentStateMachine> mEnvironment;
		shared_ptr<MonsterStateMachine> mMonsterStateMachine;		

	};

}
