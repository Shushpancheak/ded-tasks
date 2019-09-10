#pragma once
#include "Buffer.h"
#include <vector>
#include <string_view>
#include <cassert>
#include <algorithm>
#include <cctype>

/**
 * \brief An array of string_view, works on Buffer
 * and can sort string with given comparators.
 */
class StringViewManager {
public:
	/**
	 * \brief Copy data from file to a buffer and initialize the manager on that buffer.
	 */
	StringViewManager(const char* file_name);

	/**
	 * \brief Sort strings comparing lexicographically from left.
	 */
	void SortFromLeft();
	/**
	 * \brief Sort strings comparing lexicographically from right.
	 */
	void SortFromRight();

	/**
	 * \brief Write current sorted strings to the file.
	 */
	void WriteCurrentDataToFile(const char* file_name) const;
	/**
	 * \brief Write data from original file to other file.
	 */
	void WriteOriginalDataToFIle(const char* file_name) const;

	~StringViewManager();

private:
	std::string_view* string_views_;
	size_t string_count_;
	Buffer buf_;

	static bool CompareStringViewsFromLeft(const std::string_view& s1, const std::string_view& s2);
	static bool CompareStringViewsFromRight(const std::string_view& s1, const std::string_view& s2);
};
