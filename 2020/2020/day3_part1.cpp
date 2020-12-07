#include "main.h"
#include <fstream>

long long int solution_3_1(void)
{
  std::ifstream infile("3.txt");

  int trees = 0;
  int currentX = 0;

  std::string line;
  while (infile >> line) {
    if (line[currentX] == '#') trees++;
    currentX += 3;
    if (currentX > 30) currentX -= 31;
  }

  return trees;
}
