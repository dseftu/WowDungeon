#include "pch.h"
#include "ActionList.h"

namespace WowDungeon
{
	ActionList::ActionList()
	{
	}



	vector<shared_ptr<Action>>& ActionList::Actions()
	{
		// TODO: insert return statement here
		return mActions;
	}
	void ActionList::operator()()
	{
	}

}
