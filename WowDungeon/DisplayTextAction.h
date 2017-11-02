#pragma once
#include "Action.h"
#include <string>

namespace WowDungeon
{
	using namespace std;

	class DisplayTextAction : public Action
	{

	public:

		DisplayTextAction(std::string text) { SetText(text); };
		virtual void Do();

		void SetText(std::string text) { mText = text; };
		std::string GetText() { return mText; };
	private:
		std::string mText;

	};
}

