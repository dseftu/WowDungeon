#pragma once
#include "IDungeonRoomState.h"


namespace WowDungeon
{
	class Dungeon
	{
	public:
		void AttemptMove(WowDungeon::Direction direction);
		std::wstring GetFlavorText();
		void update();

	private:
		std::shared_ptr<WowDungeon::IDungeonRoomState> mCurrentRoom;

		bool mLastMoveFailed = false;
	};
}
