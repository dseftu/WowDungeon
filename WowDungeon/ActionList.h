#pragma once
#include "Action.h"

namespace WowDungeon
{

	class ActionList :
		public Action
	{
	public:

		virtual void Do() override;

		void AddAction(shared_ptr<Action> action);

	protected:
		vector<shared_ptr<Action>> mActions;
	};

}
