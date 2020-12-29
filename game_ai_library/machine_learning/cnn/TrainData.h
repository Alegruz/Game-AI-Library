#pragma once

#include <vector>

#include "Image.h"

namespace gal
{
	class TrainData
	{
	public:
		TrainData(eDataType dataType, const std::string& fileName, size_t dataSize);
		virtual ~TrainData();

		const std::string& GetFileName() const;
		size_t GetDataSize() const;
		const Image& operator[](size_t index) const;
	private:
		eDataType mDataType;
		std::string mFileName;
		size_t mDataSize;
		std::vector<std::unique_ptr<Image>> mImages;
	};
}