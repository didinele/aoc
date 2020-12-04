#include "main.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int solution_1_1(void) {
  std::ifstream infile("1.txt");
  std::vector<int> inputs(200);

  int a;
  while (infile >> a) {
    inputs.push_back(a);
  }

  int result;

  for (int i = 0; i < inputs.size(); i++) {
    int current = inputs[i];
    for (int element : inputs) {
      if (current + element == 2020) {
        result = current * element;
        break;
      }
    }
  }

  return result;
}
