#pragma once
#include <cstdio>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "sys/stat.h"
#include <cassert>

/**
 * \brief Basic interface for byte buffer.
 */
class Buffer {
public:
	/**
	 * \brief Copy data from file to buffer.
	 */
	void Store(const char* file_name);
	/**
	 * \brief Access the i-th element of the buffer.
	 */
	char& operator[](int i) const;
	/**
	 * \brief Get the size of the buffer.
	 */
	size_t GetSize() const;

	/**
	 * Write all buffer to file.
	 */
	void WriteToFile(const char* file_name) const;

	~Buffer();

private:
	char* buf_ = nullptr;
	size_t buf_size_ = 0;
};
