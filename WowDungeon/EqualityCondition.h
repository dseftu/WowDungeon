#pragma once
#include "Condition.h"

namespace WowDungeon
{
	using namespace std;

	template <typename T>
	class EqualityCondition : public Condition
	{
		
	public:
		EqualityCondition() = default;
		EqualityCondition(T a, T b)
		{
			SetOperands(a, b);
		};

		virtual bool Evaluate() override
		{
			//if (mA == nullptr || mB == nullptr) return false;
			return mA == mB;
		};

		void SetOperands(T a, T b)
		{
			SetOperandA(a);
			SetOperandB(b);
		};

		void SetOperandA(T a)
		{
			mA = a;
		};
		void SetOperandB(T b)
		{
			mB = b;
		};

		T GetOperandA() const
		{
			return mA;
		};

		T GetOperandB() const
		{
			return mB;
		};


	protected:
		T mA;
		T mB;
	};
}

