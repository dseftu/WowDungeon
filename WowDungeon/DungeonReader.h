#pragma once
#include <string>
#include "IDungeonRoomState.h"
#include <cstdint>
#include "Utility.h"

namespace WowDungeon
{
	class DungeonReader final
	{
	public:
		static std::shared_ptr<WowDungeon::IDungeonRoomState> LoadDungeonFromFile(const std::string& filename);
	};
}


