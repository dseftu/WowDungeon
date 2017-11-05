#include "pch.h"
#include "StateMachine.h"

namespace WowDungeon
{
	shared_ptr<State> StateMachine::Update()
	{
		assert(mCurrentState != nullptr);

		auto targetState = State::Update();
		if (targetState == nullptr)
		{
			targetState = mCurrentState->Update();
			if (targetState != nullptr)
			{
				mCurrentState->Exit();
				mCurrentState = targetState;
				mCurrentState->Enter();
			}
		}
		return targetState;
	}
	void StateMachine::AddState(shared_ptr<State> state)
	{
		mStates.insert({ state->Name(), state });
	}
	void StateMachine::AddState(vector<shared_ptr<State>> states)
	{
		for (auto& state : states)
		{
			AddState(state);
		}
	}
}