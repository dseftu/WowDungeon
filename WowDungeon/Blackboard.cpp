#include "pch.h"
#include "Blackboard.h"

void WowDungeon::Blackboard::UpdatePlayerLastDirection()
{
	string tempCommand = boost::to_upper_copy<std::string>(*mCommand);

	// only update if the command word matches
	if (tempCommand == "NORTH") mPlayerLastDirection = Direction::North;
	else if (tempCommand == "SOUTH") mPlayerLastDirection = Direction::South;
	else if (tempCommand == "WEST") mPlayerLastDirection = Direction::West;
	else if (tempCommand == "EAST") mPlayerLastDirection = Direction::East;
	else mPlayerLastDirection = Direction::None;
}
