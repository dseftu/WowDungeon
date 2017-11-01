#pragma once

namespace WowDungeon
{
	using namespace std;

	class Condition
	{

	public:
		virtual bool Evaluate() = 0;

	private:
		bool mValue;

	};
}

