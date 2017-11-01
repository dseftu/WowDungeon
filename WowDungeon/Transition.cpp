#include "pch.h"
#include "Transition.h"

namespace WowDungeon
{
	Transition::Transition()
	{
	}


	Transition::~Transition()
	{
	}
	shared_ptr<Condition> Transition::GetCondition()
	{
		return shared_ptr<Condition>();
	}
	bool Transition::isTriggered()
	{
		return false;
	}
	Transition & Transition::operator=(Transition & transition)
	{
		// TODO: insert return statement here
	}

	shared_ptr<State> Transition::Target()
	{
		return shared_ptr<State>();
	}
}