#pragma once

#include "Layer.h"

namespace gal
{
	class ConvLayer: public Layer
	{
	public:
		ConvLayer(size_t inputNodeCount, size_t outputNodeCount);
		ConvLayer(const ConvLayer& other);
		ConvLayer& operator=(const ConvLayer& other);
	};
}