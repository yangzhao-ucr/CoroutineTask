#include <iostream>

#include "coroutine_task.h"

using namespace coroutine_task;

static const char *const HEADER = "Coroutine Task © 2023 Yang Zhao yangzhao.ucr@gmail.com.\n\n";
static const char *const USAGE = "Usage:\n\tcoroutine_main\n";

void log(std::string msg)
{
    std::cout << msg << "\n";
}

Coroutine_Task<int> Task1()
{
    log("Task1: running");
    co_return 1;
}

Coroutine_Task<int> Task2()
{   
    log("Task2: running");
    co_return 2;
}

Coroutine_Task<std::string> TaskStr()
{   
    co_return std::string("abc");
}


Coroutine_Task<int> Task3()
{
    int r = co_await Task1() + (co_await TaskStr()).length();
    co_return r;
}

int main(int argc, const char *argv[]) {
    std::cout << HEADER;

    auto t = Task3();
    t.Resume();

    std::cout << "Task3 returns " << t.GetReturnValue() << "\n\n";

    // ensure the correct number of parameters are used.
    if (argc < 3) {
      std::cout << USAGE;
      return 1;
    }
    return 0;
}
