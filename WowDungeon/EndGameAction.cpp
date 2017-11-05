#pragma once
#include "pch.h"
#include "EndGameAction.h"


namespace WowDungeon
{
	EndGameAction::EndGameAction(shared_ptr<Blackboard> blackboard)
	{
		mBlackboard = blackboard;
	}
	void EndGameAction::Do()
	{
		mBlackboard->EndGame();
	}

}