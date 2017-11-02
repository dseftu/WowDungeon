#include "pch.h"
#include "State.h"
#include "Transition.h"

namespace WowDungeon
{
	State::State(string name, shared_ptr<Action> enter, shared_ptr<Action> exit)
	{
		mName = name;
		SetEnter(enter);
		SetExit(exit);
	}

	shared_ptr<State> State::Update()
	{
		for (auto& transition : mTransitions)
		{
			if (transition->IsTriggered())
			{
				Exit();
				transition->Target()->Enter();
				return transition->Target();			
			}
		}
		return nullptr;
	}
}
