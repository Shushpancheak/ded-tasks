#include "Buffer.h"
#include <cassert>

void Buffer::Store(const char* file_name) {
  // Deleting the old data.
  if (buf_size_) {
    delete[] buf_;
  }

  struct stat file_stats;
  stat(file_name, &file_stats);
  buf_size_ = file_stats.st_size;

  FILE* file_ptr = nullptr;
  while (file_ptr == nullptr) {
    fopen_s(&file_ptr, file_name, "r");
    if (file_ptr == nullptr) {
      printf("Please provide a file %s", file_name);
      std::this_thread::sleep_for(std::chrono::seconds(5));
    }
  }

  // + 1 for an additional \0, if it wasn't provided
  ++buf_size_;
  buf_ = new char[buf_size_];
  const size_t read_res = fread_s(buf_, buf_size_, sizeof(char), buf_size_, file_ptr);
  buf_[buf_size_ - 1] = '\0';

  fclose(file_ptr);
}

char& Buffer::operator[](int i) const {
  return buf_[i];
}

size_t Buffer::GetSize() const {
  return buf_size_;
}

void Buffer::WriteToFile(const char* file_name) const {
  FILE* file = nullptr;
  fopen_s(&file, file_name, "wb");

  assert(("Could not create a file", file != nullptr));

  for (size_t i = 0; i < buf_size_; ++i) {
    if (buf_[i] == '\0') {
      fputc('\n', file);
    } else {
      fputc(buf_[i], file);
    }
  }

  fclose(file);
}

Buffer::~Buffer() {
  if (buf_size_) {
    delete[] buf_;
  }
}
