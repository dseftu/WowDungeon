#include "pch.h"
#include "Transition.h"

namespace WowDungeon
{
	Transition::Transition(shared_ptr<Condition> condition, shared_ptr<State> target)
	{
		SetCondition(condition);
		SetTarget(target);
	}
	shared_ptr<Condition> Transition::GetCondition()
	{
		return mCondition;
	}
	bool Transition::IsTriggered()
	{
		return mCondition->Evaluate();
	}
	void Transition::SetCondition(shared_ptr<Condition> condition)
	{
		mCondition = condition;
	}
	void Transition::SetTarget(shared_ptr<State> state)
	{
		mTarget = state;
	}
	shared_ptr<State> Transition::Target()
	{
		return mTarget;
	}
}