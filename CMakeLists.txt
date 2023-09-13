cmake_minimum_required(VERSION 3.2)

project(CoroutineTask)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(COROUTINE_TASK_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(COROUTINE_TASK_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(COROUTINE_TASK_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

# set(DIVISION_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/division)

include_directories(${COROUTINE_TASK_INSTALL_INCLUDE_DIR})
# include_directories(${DIVISION_HEADERS_DIR})

add_subdirectory(src)
if(${TEST})
    add_subdirectory(test)
else()
    message("TEST is OFF, will not build. Add -DTEST=True if you want to build test.")
endif()
