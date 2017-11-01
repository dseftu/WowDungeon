#pragma once
#include "Condition.h"
#include "State.h"
#include "RTTI.h"
#include <vector>

namespace WowDungeon
{
	using namespace std;
	class Transition : public RTTI
	{
		RTTI_DECLARATIONS(Transition, RTTI)
	public:
		Transition();
		~Transition();
		shared_ptr<Condition> GetCondition();
		bool isTriggered();
		Transition& operator=(Transition& transition);
		virtual void SetCondition(shared_ptr<Condition> condition) = 0;
		virtual void SetTarget(shared_ptr<State> target) = 0;
		shared_ptr<State> Target();

	protected:
		shared_ptr<Condition> mCondition;
		shared_ptr<State> mTarget;
	};

}