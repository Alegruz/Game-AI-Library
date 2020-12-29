#include <cassert>

#include "Image.h"

namespace gal
{
	Image::Image(char label, size_t channelCount, size_t width, size_t height, byte_t***&& image)
		: mLabel(label)
		, mChannelCount(channelCount)
		, mWidth(width)
		, mHeight(height)
		, mImage(std::move(image))
	{
		image = nullptr;
	}

	Image::Image(char label, size_t channelCount, size_t width, size_t height)
		: mLabel(label)
		, mChannelCount(channelCount)
		, mWidth(width)
		, mHeight(height)
		, mImage(std::make_unique<byte_t**[]>(mChannelCount))
	{
		for (size_t channelIndex = 0; channelIndex < mChannelCount; ++channelIndex)
		{
			mImage[channelIndex] = new byte_t*[mHeight];
			for (size_t heightIndex = 0; heightIndex < mHeight; ++heightIndex)
			{
				mImage[channelIndex][heightIndex] = new byte_t[mWidth];
			}
		}
	}

	Image::Image(const Image& other)
		: mLabel(other.mLabel)
		, mChannelCount(other.mChannelCount)
		, mWidth(other.mWidth)
		, mHeight(other.mHeight)
	{
		if (this != &other)
		{
			mImage = std::make_unique<byte_t**[]>(mChannelCount);

			for (size_t channelIndex = 0; channelIndex < mChannelCount; ++channelIndex)
			{
				mImage[channelIndex] = new byte_t*[mHeight];
				for (size_t heightIndex = 0; heightIndex < mHeight; ++heightIndex)
				{
					mImage[channelIndex][heightIndex] = new byte_t[mWidth];
					for (size_t widthIndex = 0; widthIndex < mWidth; ++widthIndex)
					{
						mImage[heightIndex][widthIndex] = other.mImage[heightIndex][widthIndex];
					}
				}
			}
		}
	}

	Image::~Image()
	{
		for (size_t channelIndex = 0; channelIndex < mChannelCount; ++ channelIndex)
		{
			for (size_t heightIndex = 0; heightIndex < mHeight; ++heightIndex)
			{
				delete[] mImage[channelIndex][heightIndex];
			}
			delete[] mImage[channelIndex];
		}
		mImage.reset();
		mImage = nullptr;
	}

	Image& Image::operator=(const Image& other)
	{
		if (this != &other)
		{
			mLabel = other.mLabel;
			if (mChannelCount != other.mChannelCount || mHeight != other.mHeight || mWidth != other.mWidth)
			{
				for (size_t channelIndex = 0; channelIndex < mChannelCount; ++channelIndex)
				{
					for (size_t heightIndex = 0; heightIndex < mHeight; ++heightIndex)
					{
						delete[] mImage[channelIndex][heightIndex];
					}

					delete[] mImage[channelIndex];
				}
				
				if (mChannelCount != other.mChannelCount)
				{
					mImage.reset();
					mImage = nullptr;
					mImage = std::make_unique<byte_t**[]>(other.mChannelCount);
				}

				for (size_t channelIndex = 0; channelIndex < other.mChannelCount; ++channelIndex)
				{
					mImage[channelIndex] = new byte_t*[mHeight];
					for (size_t heightIndex = 0; heightIndex < other.mHeight; ++heightIndex)
					{
						mImage[channelIndex][heightIndex] = new byte_t[other.mWidth];
						for (size_t widthIndex = 0; widthIndex < other.mWidth; ++widthIndex)
						{
							mImage[channelIndex][heightIndex][widthIndex] = other.mImage[channelIndex][heightIndex][widthIndex];
						}
					}
				}

				mChannelCount = other.mChannelCount;
				mWidth = other.mWidth;
				mHeight = other.mHeight;
			}
			else
			{
				for (size_t channelIndex = 0; channelIndex < other.mChannelCount; ++channelIndex)
				{
					for (size_t heightIndex = 0; heightIndex < mHeight; ++heightIndex)
					{
						for (size_t widthIndex = 0; widthIndex < mWidth; ++widthIndex)
						{
							mImage[channelIndex][heightIndex][widthIndex] = other.mImage[channelIndex][heightIndex][widthIndex];
						}
					}
				}
			}
		}

		return *this;
	}
	
	byte_t**& Image::operator[](size_t index)
	{
		assert(index < mChannelCount);

		return mImage[index];
	}

	int Image::GetLabel() const
	{
		return static_cast<int>(mLabel);
	}

	size_t Image::GetChannelCount() const
	{
		return mChannelCount;
	}

	size_t Image::GetWidth() const
	{
		return mWidth;
	}

	size_t Image::GetHeight() const
	{
		return mHeight;
	}

	std::istream& operator>>(std::istream& is, Image& image)
	{
		is.read(&image.mLabel, 1);
		assert(0 <= image.mLabel && image.mLabel <= 9);

		std::string trash;
		for (size_t channel = 0; channel < image.mChannelCount; ++channel)
		{
			for (size_t heightIndex = 0; heightIndex < image.mHeight && !is.eof(); ++heightIndex)
			{
				is.read(image.mImage[channel][heightIndex], image.mWidth);

				if (is.fail())
				{
					if (is.eof())
					{
						goto loopTermination;
					}

					is.clear();
					is >> trash;
				}
			}
		}
	loopTermination:
		return is;
	}
}