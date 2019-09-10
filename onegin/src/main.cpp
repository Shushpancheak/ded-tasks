/*
 * Strings are read from file FILE_NAME. They are sorted and outputted in ways:
 * 1) Comparing from left to right
 * 2) Comparing from right to left
 * 3) Untouched text
 */

#include "Buffer.h"
#include "StringViewManager.h"

int main() {
	const char* const FILE_NAME = "res/data.in";
	const char* const DATA1_NAME = "data1.out";
	const char* const DATA2_NAME = "data2.out";
	const char* const DATA3_NAME = "data3.out";

	StringViewManager manager(FILE_NAME);

	manager.SortFromLeft();
	manager.WriteCurrentDataToFile(DATA1_NAME);

	manager.SortFromRight();
	manager.WriteCurrentDataToFile(DATA2_NAME);

	manager.WriteOriginalDataToFIle(DATA3_NAME);

	return 0;
}
