#pragma once
#include "Condition.h"

namespace WowDungeon
{
	class NotCondition :
		public Condition
	{
	public:
		NotCondition() = delete;
		NotCondition(shared_ptr<Condition> condition) { mCondition = condition; };
		virtual bool Evaluate() override { return !mCondition->Evaluate(); };

	private:
		shared_ptr<Condition> mCondition;

	};
}

