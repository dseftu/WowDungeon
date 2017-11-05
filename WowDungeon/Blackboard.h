#pragma once
#include "pch.h"
#include <string>
#include "StandardConditionDirections.h"

namespace WowDungeon
{
	using namespace std;

	

	class Blackboard
	{
	public:
		Blackboard() = delete;
		Blackboard(shared_ptr<string> command) { SetCommandString(command); };
		void SetPlayerCurrentRoom(string room) { mPlayerCurrentRoom = room; };
		const string GetPlayerCurrentRoom() { return mPlayerCurrentRoom; };

		void UpdatePlayerLastDirection();
		const Direction GetPlayerLastDirection() { return mPlayerLastDirection; };

		void SetCommandString(shared_ptr<string> command) { mCommand = command; };
		shared_ptr<string> GetCommandString() { return mCommand; };

		bool Continue() { return mContinue; };
		void EndGame() { mContinue = false; };
	private:
		string mPlayerCurrentRoom;
		Direction mPlayerLastDirection;
		shared_ptr<string> mCommand;
		bool mContinue = true;
	};
}

