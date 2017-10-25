#include "pch.h"
#include "Dungeon.h"

namespace WowDungeon
{

	void WowDungeon::Dungeon::AttemptMove(WowDungeon::Direction direction)
	{
		std::shared_ptr<WowDungeon::IDungeonRoomState> room = mCurrentRoom->AttemptTravel(direction);

		if (room != nullptr)
		{
			mCurrentRoom = room;
			mLastMoveFailed = true;
		}
		else
		{
			mLastMoveFailed = true;
		}
	}
	std::wstring Dungeon::GetFlavorText()
	{
		// return flavor text
		if (!mLastMoveFailed)
		{
			return mCurrentRoom->GetRoomDescription();
		}
		else
		{
			// TODO -> Add in some error text too.
			return mCurrentRoom->GetRoomDescription();
		}
	}
	void Dungeon::update()
	{
	}
}
