#include "main.h"
#include <fstream>
#include <string>
#include <vector>

long long int solution_1_1(void)
{
  std::ifstream infile("1.txt");
  // Initially doing std::vector<int> inputs(200) caused later pointless iterations where our value was just the default 0
  std::vector<int> inputs;
  inputs.reserve(200);

  int result;
  int current;

  bool done = false;
  while (infile >> current) {
    for (int existing : inputs) {
      if (current + existing == 2020) {
        result = current * existing;
        done = true;
        break;
      }
    }

    if (done) break;
    inputs.push_back(current);
  }

  return result;
}
