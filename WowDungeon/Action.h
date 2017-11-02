#pragma once

namespace WowDungeon
{
	using namespace std;

	class Action
	{

	public:
		Action() = default;
		virtual void Do() = 0;

	protected:
		string mName;
		
	};
}

