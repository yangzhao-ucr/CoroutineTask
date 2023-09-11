cmake_minimum_required(VERSION 3.2)
project(coroutine_task)

set(SOURCE_FILES    
    coroutine_task.cpp
)

add_library(coroutine_task SHARED STATIC ${SOURCE_FILES})

install(TARGETS coroutine_task DESTINATION ${COROUTINE_TASK_INSTALL_LIB_DIR})

