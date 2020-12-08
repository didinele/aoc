#include "main.h"
#include <fstream>

long long int solution_3_1(void)
{
  std::ifstream infile("3.txt");

  int trees = 0;
  int current_x = 0;

  std::string line;
  while (infile >> line) {
    if (line[current_x] == '#') trees++;
    current_x += 3;
    if (current_x > 30) current_x -= 31;
  }

  return trees;
}
