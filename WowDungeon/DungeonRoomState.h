#pragma once
#include "IDungeonRoomState.h"

namespace WowDungeon
{
	class DungeonRoomState : public IDungeonRoomState
	{
	public:

		// Inherited via IDungeonRoomState
		virtual std::shared_ptr<WowDungeon::IDungeonRoomState> AttemptTravel(WowDungeon::Direction direction) override;

		virtual std::wstring GetRoomDescription() override;

		virtual void SetRoom(WowDungeon::Direction direction, std::shared_ptr<WowDungeon::IDungeonRoomState> room);
		virtual void SetFlavorText(std::wstring flavorText);


	};

}
