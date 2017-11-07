#pragma once
#include "pch.h"
#include "MonsterChaseAction.h"
namespace WowDungeon
{

	WowDungeon::MonsterChaseAction::MonsterChaseAction(shared_ptr<EnvironmentStateMachine> environment, shared_ptr<MonsterStateMachine> monsterStateMachine)
	{
		mEnvironment = environment;
		mMonsterStateMachine = monsterStateMachine;
		
	}

	void WowDungeon::MonsterChaseAction::Do()
	{
		// This has the effect of having the monster "follow" the player for one frame
		// this could be abused to "teleport" the monster as well.
		mMonsterStateMachine->SetMonsterCurrentRoom(mEnvironment->GetPlayerCurrentRoom());
	}

}