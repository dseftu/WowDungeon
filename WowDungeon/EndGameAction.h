#pragma once
#include "Action.h"
#include "Blackboard.h"
namespace WowDungeon
{
	using namespace std;
	class Blackboard;

	class EndGameAction :
		public Action
	{
		
	public:
		EndGameAction() = delete;
		EndGameAction(shared_ptr<Blackboard> blackboard);

		// Inherited via Action
		virtual void Do() override;

	private:
		shared_ptr<Blackboard> mBlackboard;
	};

}
