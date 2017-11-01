#pragma once
#include "State.h"

namespace WowDungeon
{
	using namespace std;
	class StateMachine :
		public State
	{
	public:
		StateMachine();
		~StateMachine();
		void AddState(shared_ptr<State> state);
		void AddStates(vector<shared_ptr<State>> states);
		shared_ptr<State> CurrentState();
		void Initialize();
		StateMachine& operator=(StateMachine& stateMachine);
		void SetCurrentState(shared_ptr<State> state);
		const map<string, shared_ptr<State>>& States();
		shared_ptr<State> Update();

	};
}
