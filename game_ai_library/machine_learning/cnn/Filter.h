#pragma once

#include <cassert>
#include <cstddef>
#include <memory>
#include <vector>

namespace gal
{
	template <typename T>
	class Filter
	{
	public:
		Filter(size_t width, size_t height);
		Filter(size_t size);
		Filter(const Filter& other);
		virtual ~Filter();

		Filter& operator=(const Filter& other);
		std::vector<T>& operator[](size_t index);

		size_t GetWidth() const;
		size_t GetHeight() const;
	private:
		size_t mWidth;
		size_t mHeight;
		T** mFilter;
	};

	template <typename T>
	Filter<T>::Filter(size_t width, size_t height)
		: mWidth(width)
		, mHeight(height)
		, mFilter(new T*[mHeight])
	{
		for (size_t heightIndex = 0; heightIndex < mHeight; ++heightIndex)
		{
			mFilter[heightIndex] = new T[mWidth];
		}
	}

	template <typename T>
	Filter<T>::Filter(size_t size)
		: Filter(size, size)
	{
	}

	template <typename T>
	Filter<T>::Filter(const Filter& other)
		: mWidth(other.mWidth)
		, mHeight(other.mHeight)
	{
		if (this != &other)
		{
			mFilter = new Filter*[mHeight];
			for (size_t heightIndex = 0; heightIndex < mHeight; ++heightIndex)
			{
				mFilter[heightIndex] = new T[mWidth];
				for (size_t widthIndex = 0; widthIndex < mWidth; ++widthIndex)
				{
					mFilter[heightIndex][widthIndex] = other.mFilter[heightIndex][widthIndex];
				}
			}
		}
	}

	template <typename T>
	Filter<T>::~Filter()
	{
		for (size_t heightIndex = 0; heightIndex < mHeight; ++heightIndex)
		{
			delete[] mFilter[heightIndex];
		}
		delete[] mFilter;
	}

	template <typename T>
	Filter<T>& Filter<T>::operator=(const Filter& other)
	{
		if (this != &other)
		{
			if (mHeight != other.mHeight || mWidth != other.mWidth)
			{
				for (size_t heightIndex = 0; heightIndex < mHeight; ++heightIndex)
				{
					delete[] mFilter[heightIndex];
				}
				
				if (mHeight != other.mHeight)
				{
					delete[] mFilter;
					mFilter = new T*[other.mHeight];
				}

				for (size_t heightIndex = 0; heightIndex < other.mHeight; ++heightIndex)
				{
					mFilter[heightIndex] = new T[other.mWidth];
					for (size_t widthIndex = 0; widthIndex < other.mWidth; ++widthIndex)
					{
						mFilter[heightIndex][widthIndex] = other.mFilter[heightIndex][widthIndex];
					}
				}

				mWidth = other.mWidth;
				mHeight = other.mHeight;
			}
			else
			{
				for (size_t heightIndex = 0; heightIndex < mHeight; ++heightIndex)
				{
					for (size_t widthIndex = 0; widthIndex < mWidth; ++widthIndex)
					{
						mFilter[heightIndex][widthIndex] = other.mFilter[heightIndex][widthIndex];
					}
				}
			}
		}

		return *this;
	}

	template <typename T>
	std::vector<T>& Filter<T>::operator[](size_t index)
	{
		assert(index < mHeight);

		return mFilter[index];
	}

	template <typename T>
	size_t Filter<T>::GetHeight() const
	{
		return mHeight;
	}

	template <typename T>
	size_t Filter<T>::GetWidth() const
	{
		return mWidth;
	}
}