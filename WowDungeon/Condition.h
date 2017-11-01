#pragma once
#include "RTTI.h"
namespace WowDungeon
{
	using namespace std;

	class Condition : public RTTI
	{
		RTTI_DECLARATIONS(Condition, RTTI)

	public:
		Condition();
		~Condition();
		bool operator()();
		Condition& operator=(Condition& condition);
	};
}

