#pragma once
#include "State.h"
#include <string>

namespace WowDungeon
{
	using namespace std;
	class StateMachine :
		public State
	{
	public:
		virtual void Initialize() = 0;

		shared_ptr<State> Update();

		void AddState(shared_ptr<State> state);
		void AddState(vector<shared_ptr<State>> states);
		shared_ptr<State> CurrentState() { return mCurrentState; };
		void SetCurrentState(shared_ptr<State> state) { mCurrentState = state; };
		const map<string, shared_ptr<State>>& States() { return mStates; };

	private:
		shared_ptr<State> mCurrentState;
		map<string, shared_ptr<State>> mStates;
		

	};
}
