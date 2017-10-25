#include "pch.h"
#include "DungeonRoomState.h"

std::shared_ptr<WowDungeon::IDungeonRoomState> WowDungeon::DungeonRoomState::AttemptTravel(WowDungeon::Direction direction)
{
	return rooms[direction];
}

std::wstring WowDungeon::DungeonRoomState::GetRoomDescription()
{
	return mFlavorText;
}

void WowDungeon::DungeonRoomState::SetRoom(WowDungeon::Direction direction, std::shared_ptr<WowDungeon::IDungeonRoomState> room)
{
	rooms[direction] = room;
}

void WowDungeon::DungeonRoomState::SetFlavorText(std::wstring flavorText)
{	
	mFlavorText = flavorText;
}
