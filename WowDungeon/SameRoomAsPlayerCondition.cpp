#pragma once
#include "pch.h"
#include "SameRoomAsPlayerCondition.h"

namespace WowDungeon
{
	SameRoomAsPlayerCondition::SameRoomAsPlayerCondition(shared_ptr<EnvironmentStateMachine> environment, shared_ptr<MonsterStateMachine> monsterStateMachine)
	{
		mEnvironment = environment;
		mMonsterStateMachine = monsterStateMachine;
	}
	bool SameRoomAsPlayerCondition::Evaluate()
	{
		return mEnvironment->GetPlayerCurrentRoom() == mMonsterStateMachine->GetMonsterCurrentRoom();		
	}



}