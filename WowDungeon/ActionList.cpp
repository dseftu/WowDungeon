#include "pch.h"
#include "ActionList.h"

namespace WowDungeon
{
	void WowDungeon::ActionList::Do()
	{
		for (auto& action : mActions) action->Do();
	}
	void ActionList::AddAction(shared_ptr<Action> action)
	{
		mActions.push_back(action);
	}
}