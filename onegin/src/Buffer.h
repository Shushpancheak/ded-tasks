#pragma once
#include <cstdio>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "sys/stat.h"

/**
 * \brief Basic interface for byte buffer.
 */
class Buffer {
public:
  void Store(const char* file_name);
  char& operator[](int i) const;
  size_t GetSize() const;

  void WriteToFile(const char* file_name) const;

  ~Buffer();

private:
  char* buf_ = nullptr;
  size_t buf_size_ = 0;
};

