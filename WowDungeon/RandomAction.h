#pragma once
#include "ActionList.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

namespace WowDungeon
{
	class RandomAction :
		public ActionList
	{
	public:
		virtual void Do() override;
	};

}
