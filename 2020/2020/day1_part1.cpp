#include "main.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int solution_1_1(void) {
  std::ifstream infile("1.txt");
  std::vector<int> inputs(200);

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
