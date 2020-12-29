#pragma once

namespace gal
{
	typedef char byte_t;

	enum class eDataType
	{
		CIFAR10
	};

	const size_t CIFAR10_CHANNEL_COUNT = 3UL;
	const size_t CIFAR10_IMAGE_SIZE = 32UL;
	const size_t CIFAR10_PIXEL_COUNT_PER_CHANNEL = 1024UL;

	const size_t VGGNET_IMAGE_CHANNEL_COUNT = 3UL;
	const size_t VGGNET_IMAGE_SIZE = 224UL;
}