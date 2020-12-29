#include <cassert>
#include <fstream>

#include "TrainData.h"

namespace gal
{
	TrainData::TrainData(eDataType dataType, const std::string& fileName, size_t dataSize)
		: mDataType(dataType)
		, mFileName(fileName)
		, mDataSize(dataSize)
	{
		mImages.reserve(mDataSize);
		std::ifstream dataFile(fileName, std::ios::in | std::ios::binary);

		size_t dataIndex = 0;
		std::string trash;
		while (!dataFile.eof() && dataSize <= mDataSize)
		{
			switch (dataType)
			{
			case eDataType::CIFAR10:
				mImages.push_back(std::make_unique<Image>('\0', CIFAR10_CHANNEL_COUNT, CIFAR10_IMAGE_SIZE, CIFAR10_IMAGE_SIZE));
				break;
			default:
				assert(false);
				break;
			}

			// dataFile >> **mImages.rbegin();
			if (dataFile.fail())
			{
				if (dataFile.eof())
				{
					break;
				}
				dataFile.clear();
				dataFile >> trash;
			}
			else
			{
				++dataIndex;
			}
		}

		dataFile.close();

		assert(dataIndex == mDataSize);
	}
	
	TrainData::~TrainData()
	{
	}

	const std::string& TrainData::GetFileName() const
	{
		return mFileName;
	}

	size_t TrainData::GetDataSize() const
	{
		return mDataSize;
	}

	const Image& TrainData::operator[](size_t index) const
	{
		assert(index < mDataSize);

		return *mImages[index];
	}
}