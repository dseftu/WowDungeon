#include "pch.h"
#include "Condition.h"

namespace WowDungeon
{
	Condition::Condition()
	{
	}


	Condition::~Condition()
	{
	}

	bool WowDungeon::Condition::operator()()
	{
		return false;
	}

	Condition & WowDungeon::Condition::operator=(Condition & condition)
	{
		UNREFERENCED_PARAMETER(condition);
		// TODO: insert return statement here
		return condition;
	}
}