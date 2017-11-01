#pragma once
#include "Condition.h"
#include "EqualityCondition.h"
#include <memory>
#include <boost/algorithm/string.hpp>
#include <string>


namespace WowDungeon
{
	using namespace std;

	class StringEqualityCondition : public EqualityCondition<shared_ptr<string>>
	{

	public:
		StringEqualityCondition(shared_ptr<string> a, shared_ptr<string> b);
		virtual bool Evaluate() override;
	
	};
}

