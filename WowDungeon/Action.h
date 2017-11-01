#pragma once
#include "RTTI.h"

namespace WowDungeon
{
	using namespace std;

	class Action : public RTTI
	{
		RTTI_DECLARATIONS(Action, RTTI)

	public:
		Action();
		virtual ~Action() = default;
		void operator()();
		virtual Action& operator=(Action& action) = default;

	protected:
		string mName;
	};
}

