#pragma once
#include "Action.h"

namespace WowDungeon
{

	class ActionList :
		public Action
	{
	public:

		// Inherited via Action
		virtual void Do() override;

		void AddAction(shared_ptr<Action> action);

	private:
		vector<shared_ptr<Action>> mActions;
	};

}
