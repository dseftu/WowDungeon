#pragma once
#include "Action.h"

namespace WowDungeon
{
	using namespace std;
	class ActionList :
		public Action
	{
	public:
		ActionList();
		virtual ~ActionList() = default;
		vector<shared_ptr<Action>>& Actions();
		void operator()();
		ActionList& operator=(ActionList& actionList) = default;

	private:
		vector<shared_ptr<Action>> mActions;
	};
}

