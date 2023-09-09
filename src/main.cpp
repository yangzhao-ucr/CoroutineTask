#include <iostream>

#include "coroutine_task.h"

using namespace coroutine_task;

static const char *const HEADER = "Coroutine Task © 2023 Yang Zhao yangzhao.ucr@gmail.com.\n\n";
static const char *const USAGE = "Usage:\n\tcoroutine_main\n";

int main(int argc, const char *argv[]) {
  std::cout << HEADER;

  Coroutine_Task task;

  // ensure the correct number of parameters are used.
  if (argc < 3) {
    std::cout << USAGE;
    return 1;
  }
  return 0;
}
