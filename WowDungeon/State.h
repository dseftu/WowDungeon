#pragma once
#include <vector>
#include "Action.h"
#include "Transition.h"

namespace WowDungeon
{
	using namespace std;
	class Action;
	class Transition;
	class State
	{

	public:
		State() = default;
		State(string name, shared_ptr<Action> enter, shared_ptr<Action> exit);
		shared_ptr<State> Update();

		void Enter() { GetEnter()->Do(); };
		void Exit() { GetExit()->Do(); };
		void AddTransition(shared_ptr<Transition> transition) { mTransitions.push_back(transition); };
		const string& Name() { return mName; };
		shared_ptr<Action> GetEnter() { return mEnter; };
		shared_ptr<Action> GetExit() { return mExit; };
		void SetEnter(shared_ptr<Action> enter) { mEnter = enter; };
		void SetExit(shared_ptr<Action> exit) { mExit = exit; };
	private:
		string mName;
		shared_ptr<Action> mEnter;
		shared_ptr<Action> mExit;
		vector<shared_ptr<Transition>> mTransitions;
	};
}

