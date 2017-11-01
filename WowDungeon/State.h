#pragma once
#include "Action.h"
#include "Transition.h"
#include "RTTI.h"
#include <vector>

namespace WowDungeon
{
	using namespace std;

	template<class T>
	class State : public RTTI
	{
		RTTI_DECLARATIONS(State, RTTI)

	public:
		virtual ~State() = default;
		State();
		virtual void AddTransition(shared_ptr<Transition> transition) = 0;
		virtual void AddTransitions(vector<shared_ptr<Transition>> transitions) = 0;
		virtual void Enter() = 0;
		virtual void Exit() = 0;
		shared_ptr<Action> GetEnter();
		shared_ptr<Action> GetExit();
		const string& Name();
		virtual State& operator=(const State& state) = default;
		void SetEnter(shared_ptr<Action> enter);
		void SetExit(shared_ptr<Action> exit);
		void SetName(const string& name);
		const vector<shared_ptr<Transition>>& Transitions();
		shared_ptr<State> Update();
	private:
		shared_ptr<Action> mEnter;
		shared_ptr<Action> mExit;
		string mName;
		vector<shared_ptr<Transition>> mTransitions;
	};
	template<class T>
	inline shared_ptr<Action> State<T>::GetEnter()
	{
		return mEnter;
	}
	template<class T>
	inline const string & State<T>::Name()
	{
		return mName;
	}
	template<class T>
	inline void State<T>::SetEnter(shared_ptr<Action> enter)
	{
		mEnter = enter;
	}
	template<class T>
	inline void State<T>::SetExit(shared_ptr<Action> exit)
	{
		mExit = exit;
	}
	template<class T>
	inline void State<T>::SetName(const string & name)
	{
		mName = name;
	}
	template<class T>
	inline const vector<shared_ptr<Transition>>& State<T>::Transitions()
	{
		return mTransitions;
	}
	template<class T>
	inline shared_ptr<State> State<T>::Update()
	{
		return (*this);
	}
}

