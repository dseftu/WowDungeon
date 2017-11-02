#include "pch.h"
#include "DisplayTextAction.h"
#include <iostream>

namespace WowDungeon
{
	using namespace std;

	void WowDungeon::DisplayTextAction::Do()
	{
		cout << mText << endl;
	}
}
