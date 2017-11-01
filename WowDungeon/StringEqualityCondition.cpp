#include "pch.h"
#include "StringEqualityCondition.h"

namespace WowDungeon
{
	StringEqualityCondition::StringEqualityCondition(shared_ptr<string> a, shared_ptr<string> b)
	{
		SetOperandA(a);
		SetOperandB(b);
	}

	bool StringEqualityCondition::Evaluate()
	{
		string tempA = boost::to_upper_copy<std::string>(*mA);
		string tempB = boost::to_upper_copy<std::string>(*mB);
		
		return  tempA == tempB;
	}

}