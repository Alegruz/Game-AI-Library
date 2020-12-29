#pragma once

#include <memory>
#include <vector>

#include "Filter.h"

namespace gal
{
	class Layer
	{
	public:
		Layer(size_t inputNodeCount, size_t outputNodeCount);
		Layer(const Layer& other);
		virtual ~Layer();
		Layer& operator=(const Layer& other);
		std::vector<std::shared_ptr<Filter<double>>>& operator[](size_t index);
		virtual void Process() const;
	private:
		size_t mInputNodeCount;
		size_t mOutputNodeCount;
		std::vector<std::vector<std::shared_ptr<Filter<double>>>> mFilters;
	};
}