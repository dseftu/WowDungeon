#include "pch.h"
#include "StateMachine.h"

namespace WowDungeon
{
	StateMachine::StateMachine()
	{
	}


	StateMachine::~StateMachine()
	{
	}
	void StateMachine::AddState(shared_ptr<State> state)
	{
	}
	void StateMachine::AddStates(vector<shared_ptr<State>> states)
	{
	}
	shared_ptr<State> StateMachine::CurrentState()
	{
		return shared_ptr<State>();
	}
	void StateMachine::Initialize()
	{
	}
	StateMachine & StateMachine::operator=(StateMachine & stateMachine)
	{
		// TODO: insert return statement here
	}
	void StateMachine::SetCurrentState(shared_ptr<State> state)
	{
	}
	const map<string, shared_ptr<State>>& StateMachine::States()
	{
		// TODO: insert return statement here
	}
	shared_ptr<State> StateMachine::Update()
	{
		return shared_ptr<State>();
	}
}