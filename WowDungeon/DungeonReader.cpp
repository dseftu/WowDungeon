#include "pch.h"
/*
#include "DungeonReader.h"
#include "Utility.h"

namespace WowDungeon
{
	using namespace std;

	std::shared_ptr<WowDungeon::IDungeonRoomState> DungeonReader::LoadDungeonFromFile(const std::string & filename)
	{
		ifstream inputFile(filename);
		if (inputFile.bad())
		{
			throw exception("Could not open file.");
		}

		// get the number of rooms
		int32_t numRooms;
		inputFile >> numRooms;

		for (int32_t i = 0; i < numRooms; i++)
		{
			string line;		
			getline(inputFile, line);
			auto connections = Library::Utility::SplitString(line, ',');
		}
		

		inputFile.close();

		return std::shared_ptr<WowDungeon::IDungeonRoomState>();


	}
}
*/