cmake_minimum_required(VERSION 3.2)
# project(coroutinetask_main)
# add_subdirectory(coroutinetask)

project(coroutine_task)

set(SOURCE_FILES    
    coroutinetask/coroutine_task.cpp
)

add_library(coroutine_task SHARED STATIC ${SOURCE_FILES})
install(TARGETS coroutine_task DESTINATION ${COROUTINE_TASK_INSTALL_LIB_DIR})

# dummy exe
set(EXE_SOURCE_FILES main.cpp)
add_executable(coroutinetask_main ${EXE_SOURCE_FILES})
target_link_libraries(coroutinetask_main coroutine_task)

