#pragma once

#include <iostream>
#include <memory>

namespace gal
{
	class State
	{
	friend std::ostream& operator<<(std::ostream& os, const State& rhs);
	public:
		State();
		State(const char* name);
		State(const State& other) = delete;
		State(State&& other);
		virtual ~State() = default;

		State& operator=(State&& other);

		bool AddBranch(std::shared_ptr<State> state);
		bool DeleteBranch(const std::shared_ptr<State>& state);
		const char* GetName() const;
	private:
		std::unique_ptr<const char*> mName;
		unsigned int mBranchCapacity;
		unsigned int mBranchSize;
		std::unique_ptr<std::weak_ptr<State>[]> mBranches;
	};

	class FiniteStateMachine final
	{
	public:
		FiniteStateMachine() = delete;
		FiniteStateMachine(unsigned int capacity);
		FiniteStateMachine(const FiniteStateMachine& other) = delete;
		FiniteStateMachine(FiniteStateMachine&& other);
		virtual ~FiniteStateMachine() = default;

		State& operator[](const char* stateName) const;

		bool AddState(State&& state);
	private:
		unsigned int mCapacity;
		unsigned int mSize;
		std::unique_ptr<State[]> mStates;
	};
}