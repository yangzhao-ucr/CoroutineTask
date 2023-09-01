#include <iostream>

#include "coroutine_task.h"

using namespace std;

static const char *const HEADER = "\nDivider © 2018 Monkey Claps Inc.\n\n";
static const char *const USAGE = "Usage:\n\tdivider <numerator> <denominator>\n\nDescription:\n\tComputes the result of a fractional division,\n\tand reports both the result and the remainder.\n";

int main(int argc, const char *argv[]) {
  cout << HEADER;

  // ensure the correct number of parameters are used.
  if (argc < 3) {
    cout << USAGE;
    return 1;
  }
  Corountine_Task task;
  return 0;
}
