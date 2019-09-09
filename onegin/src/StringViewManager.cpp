#include "StringViewManager.h"


StringViewManager::StringViewManager(const char* file_name)
  : string_views_(nullptr)
  , string_count_(0) {
  buf_.Store(file_name);

  for (size_t i = 0; i < buf_.GetSize(); ++i) {
    if (buf_[i] == '\n') {
      buf_[i] = '\0';
    }
    if (buf_[i] == '\0') {
      ++string_count_;
    }
  }

  string_views_ = new std::string_view[string_count_];
  if (string_count_) {
    string_views_[0] = std::string_view(&buf_[0]);
  }
  size_t j = 1;
  for (size_t i = 1; i < buf_.GetSize(); ++i) {
    if (buf_[i - 1] == '\0') {
      string_views_[j++] = std::string_view(&buf_[i]);
    }
  }
}

// ReSharper disable once CppMemberFunctionMayBeConst
void StringViewManager::SortFromLeft() {
  std::sort(string_views_, string_views_ + string_count_,
  [](const std::string_view& s1, const std::string_view& s2) -> bool {
    size_t i = 0;
    size_t j = 0;
    for (; i < s1.length() && j < s2.length(); ++i, ++j) {

      // Iterating to next alpha symbol.
      while (!isalpha(static_cast<unsigned char>(s1[i]))) {
        ++i;
        if (i >= s1.length() - 1) {
          i = s1.length() - 1;
          break;
        }
      }
      while (!isalpha(static_cast<unsigned char>(s2[j]))) {
        ++j;
        if (j >= s2.length() - 1) {
          j = s2.length() - 1;
          break;
        }
      }

      if (s1[i] < s2[j]) {
        return true;
      } else if (s1[i] > s2[j]) {
        return false;
      }
    }

    return false;
  });
}

// ReSharper disable once CppMemberFunctionMayBeConst
void StringViewManager::SortFromRight() {
  std::sort(string_views_, string_views_ + string_count_,
  [](const std::string_view& s1, const std::string_view& s2) -> bool {
    int i = s1.length() - 1;
    int j = s2.length() - 1;
    for (; i >= 0 && j >= 0; --i, --j) {

      // Iterating to next alpha symbol.
      while (!isalpha(static_cast<unsigned char>(s1[i]))) {
        --i;
        if (i <= 0) {
          i = 0;
          break;
        }
      }
      while (!isalpha(static_cast<unsigned char>(s2[j]))) {
        --j;
        if (j <= 0) {
          j = 0;
          break;
        }
      }

      if (s1[i] < s2[j]) {
        return true;
      } else if (s1[i] > s2[j]) {
        return false;
      }
    }

    return false;
  });
}

void StringViewManager::WriteCurrentDataToFile(const char* file_name) const {
  FILE* file = nullptr;
  fopen_s(&file, file_name, "wb");

  assert(("Could not create a file", file != nullptr));

  for (size_t i = 0; i < string_count_; ++i) {
    if (string_views_[i].length() > 0) {
      fputs(&string_views_[i][0], file);
      fputc('\n', file);
    }
  }

  fclose(file);
}

void StringViewManager::WriteOriginalDataToFIle(const char* file_name) const {
  buf_.WriteToFile(file_name);
}

StringViewManager::~StringViewManager() {
  if (string_count_) {
    delete[] string_views_;
  }
}
