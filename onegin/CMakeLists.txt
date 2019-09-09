# CMakeList.txt : CMake project for onegin, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES	src/*.cpp src/*.h src/*.hpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

include_directories (
  "res"
  "src"
)

# Add source to this project's executable.
add_executable (
  onegin
  ${SOURCES}
)

# TODO: Add tests and install targets if needed.
