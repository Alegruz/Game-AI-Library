#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "Galdef.h"

namespace gal
{
	class Image
	{
	friend std::istream& operator>>(std::istream& is, Image& image);
	public:
		Image(char mLabel, size_t channelCount, size_t width, size_t height, byte_t***&& image);
		Image(char mLabel, size_t channelCount, size_t width, size_t height);
		Image(const Image& other);
		virtual ~Image();

		Image& operator=(const Image& other);
		byte_t**& operator[](size_t index);

		int GetLabel() const;
		size_t GetChannelCount() const;
		size_t GetWidth() const;
		size_t GetHeight() const;
	protected:
		virtual void initializeImage();

		char mLabel;
		size_t mChannelCount;
		size_t mWidth;
		size_t mHeight;
		std::unique_ptr<byte_t**[]> mImage;
	};
}