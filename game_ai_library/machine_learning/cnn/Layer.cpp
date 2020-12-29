#include <cassert>

#include "Layer.h"

namespace gal
{
	Layer::Layer(size_t inputNodeCount, size_t outputNodeCount)
		: mInputNodeCount(inputNodeCount)
		, mOutputNodeCount(mOutputNodeCount)
	{
		mFilters.reserve(mInputNodeCount);
		for (size_t inputNodeIndex = 0; inputNodeIndex < mInputNodeCount; ++inputNodeIndex)
		{
			mFilters.push_back(std::vector<std::shared_ptr<Filter<double>>>());
			mFilters[inputNodeIndex].reserve(mOutputNodeCount);
		}
	}

	Layer::Layer(const Layer& other)
	{
		if (this != &other)
		{
			for (size_t inputNodeIndex = 0; inputNodeIndex < mInputNodeCount; ++inputNodeIndex)
			{
				for (size_t outputNodeIndex = 0; outputNodeIndex < mOutputNodeCount; ++outputNodeIndex)
				{
					mFilters[inputNodeIndex][outputNodeIndex].reset();
					mFilters[inputNodeIndex][outputNodeIndex] = other.mFilters[inputNodeIndex][outputNodeIndex];
				}
			}
		}
	}

	Layer::~Layer()
	{
		for (size_t inputNodeIndex = 0; inputNodeIndex < mInputNodeCount; ++inputNodeIndex)
			{
				for (size_t outputNodeIndex = 0; outputNodeIndex < mOutputNodeCount; ++outputNodeIndex)
				{
					mFilters[inputNodeIndex][outputNodeIndex].reset();
					mFilters[inputNodeIndex][outputNodeIndex] = nullptr;
				}
			}
	}

	Layer& Layer::operator=(const Layer& other)
	{
		if (this != &other)
		{
			for (size_t inputNodeIndex = 0; inputNodeIndex < mInputNodeCount; ++inputNodeIndex)
			{
				for (size_t outputNodeIndex = 0; outputNodeIndex < mOutputNodeCount; ++outputNodeIndex)
				{
					mFilters[inputNodeIndex][outputNodeIndex].reset();
					mFilters[inputNodeIndex][outputNodeIndex] = other.mFilters[inputNodeIndex][outputNodeIndex];
				}
			}
		}

		return *this;
	}

	std::vector<std::shared_ptr<Filter<double>>>& Layer::operator[](size_t index)
	{
		assert(index < mInputNodeCount);

		return mFilters[index];
	}
}