#pragma once
#include <string>

namespace WowDungeon
{
	enum Direction
	{
		North = 0,
		East = 1,
		South = 2,
		West = 3,
	};

	class IDungeonRoomState
	{
	public:
		virtual std::shared_ptr<WowDungeon::IDungeonRoomState> AttemptTravel(WowDungeon::Direction direction) = 0;
		virtual std::wstring GetRoomDescription() = 0;

	protected:
		std::shared_ptr<WowDungeon::IDungeonRoomState> rooms[4];
		std::wstring mFlavorText;

	};
}
