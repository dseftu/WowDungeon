#pragma once
#include "Game.h"
#include "Rectangle.h"
#include "IDungeonRoomState.h"

namespace Library
{
	class KeyboardComponent;
}

namespace WowDungeon
{

	class WowDungeonGame : public Library::Game
	{
	public:
		WowDungeonGame(std::function<void*()> getWindowCallback, std::function<void(SIZE&)> getRenderTargetSizeCallback);

		virtual void Initialize() override;
		virtual void Shutdown() override;
		virtual void Update(const Library::GameTime& gameTime) override;
		virtual void Draw(const Library::GameTime& gameTime) override;

	private:
		void Exit();

		static DirectX::XMVECTORF32 BackgroundColor;

		std::shared_ptr<Library::KeyboardComponent> mKeyboard;
		
	};
}