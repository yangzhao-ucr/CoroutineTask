cmake_minimum_required(VERSION 3.2)
project(coroutinetask_tests)

add_subdirectory(lib/googletest)

# include_directories(${DIVISION_HEADERS_DIR})
include_directories(lib/googletest/googletest/include)

set(SOURCE_FILES main.cpp src/coroutinetask_test.cpp)

add_executable(coroutinetask_test ${SOURCE_FILES})
target_link_libraries(coroutinetask_test gtest)

