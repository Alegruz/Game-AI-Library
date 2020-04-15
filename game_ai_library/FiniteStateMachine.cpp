#include "FiniteStateMachine.h"

#include <cassert>

namespace gal
{
	State::State()
		: mName(nullptr)
		, mBranchCapacity(8)
		, mBranchSize(0)
		, mBranches(nullptr)
	{
	}

	State::State(const char* name)
		: mName(std::make_unique<const char*>(name))
		, mBranchCapacity(8)
		, mBranchSize(0)
		, mBranches(std::make_unique<std::weak_ptr<State>[]>(mBranchCapacity))
	{
	}

	State::State(State&& other)
		: mName(std::move(other.mName))
		, mBranchCapacity(other.mBranchCapacity)
		, mBranchSize(other.mBranchSize)
		, mBranches(std::move(other.mBranches))
	{
		other.mName = nullptr;

		for (unsigned int state = 0; state < other.mBranchSize; ++state)
		{
			other.mBranches[state].lock() = nullptr;
		}

		mBranchCapacity = 0;
		mBranchSize = 0;
		mBranches = nullptr;
	}

	bool State::AddBranch(std::shared_ptr<State> state)
	{
		if (mBranchCapacity <= mBranchSize)
		{
			return false;
		}

		mBranches[mBranchSize++] = state;

		return true;
	}

	bool State::DeleteBranch(const std::shared_ptr<State>& state)
	{
		if (mBranchSize <= 0)
		{
			return false;
		}

		bool bIsRemoved;
		for (unsigned int branch = 0; branch < mBranchSize; ++branch)
		{
			if (mBranches[branch].lock() == state)
			{
				mBranches[branch].lock() = nullptr;
				--mBranchSize;
				bIsRemoved = true;
			}

			if (bIsRemoved)
			{
				mBranches[branch] = mBranches[branch + 1];
			}
		}

		mBranches[mBranchSize].lock() = nullptr;

		return true;
	}

	const char* State::GetName() const
	{
		return *mName;
	}

	std::ostream& operator<<(std::ostream& os, const State& rhs)
	{
		os << *rhs.mName;

		return os;
	}

	State& State::operator=(State&& other)
	{
		if (mName != other.mName)
		{
			mName = nullptr;
			mName = std::move(other.mName);
			other.mName = nullptr;
		}

		if (mBranches != other.mBranches)
		{
			mBranchCapacity = other.mBranchCapacity;
			mBranchSize = other.mBranchSize;

			mBranches = nullptr;
			mBranches = std::move(other.mBranches);
			other.mBranches = nullptr;
			other.mBranchCapacity = 0;
			other.mBranchSize = 0;
		}

		return *this;
	}

	FiniteStateMachine::FiniteStateMachine(unsigned int capacity)
		: mCapacity(capacity)
		, mSize(0)
		, mStates(std::make_unique<State[]>(mCapacity))
	{
	}

	FiniteStateMachine::FiniteStateMachine(FiniteStateMachine&& other)
		: mCapacity(other.mCapacity)
		, mSize(other.mSize)
		, mStates(std::move(other.mStates))
	{
		other.mCapacity = 0;
		other.mSize = 0;
		other.mStates = nullptr;
	}

	State& FiniteStateMachine::operator[](const char* stateName) const
	{
		for (unsigned int state = 0; state < mSize; ++state)
		{
			if (mStates[state].GetName() == stateName)
			{
				return mStates[state];
			}
		}

		assert(false);
	}

	bool FiniteStateMachine::AddState(State&& state)
	{
		if (mCapacity <= mSize)
		{
			return false;
		}
		
		mStates[mSize++] = std::move(state);

		return true;
	}
}