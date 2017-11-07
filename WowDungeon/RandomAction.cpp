#include "pch.h"
#include "RandomAction.h"
namespace WowDungeon
{

	void WowDungeon::RandomAction::Do()
	{
		auto nextRand = rand();
		auto numActions = mActions.size();
		int32_t next = nextRand % numActions;
		mActions[next]->Do();
	}
}
