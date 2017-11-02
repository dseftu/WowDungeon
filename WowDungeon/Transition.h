#pragma once
#include "Condition.h"
#include <vector>

namespace WowDungeon
{
	class State;

	using namespace std;
	class Transition
	{
	public:
		Transition(shared_ptr<Condition> condition, shared_ptr<State> target);
		shared_ptr<Condition> GetCondition();
		bool IsTriggered();
		void SetCondition(shared_ptr<Condition> condition);
		void SetTarget(shared_ptr<State> target);
		shared_ptr<State> Target();

	protected:
		shared_ptr<Condition> mCondition;
		shared_ptr<State> mTarget;
		
	};

}