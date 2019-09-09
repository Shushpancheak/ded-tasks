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
   * \note Replaces all \\n's with \\0
   */
  StringViewManager(const char* file_name);

  void SortFromLeft();
  void SortFromRight();

  void WriteCurrentDataToFile(const char* file_name) const;
  void WriteOriginalDataToFIle(const char* file_name) const;

  ~StringViewManager();

private:
  std::string_view* string_views_;
  size_t string_count_;
  Buffer buf_;
};
