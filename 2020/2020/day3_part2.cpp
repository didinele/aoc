#include "main.h"
#include <fstream>

long long int solution_3_2(void)
{
  long long int result = 1;

  int slopes[5][2] = {
    { 1, 1 },
    { 3, 1 },
    { 5, 1 },
    { 7, 1 },
    { 1, 2 }
  };

  for (const auto& slope : slopes) {
    int xOffset = slope[0];
    int yOffset = slope[1];

    long long int trees = 0;
    int currentX = 0;
    int wentPast = 0;

    std::ifstream infile("3.txt");
    std::string line;
    while (infile >> line) {
      if (wentPast > 1) {
        wentPast--;
        continue;
      }

      if (line[currentX] == '#') trees++;
      currentX += xOffset;
      if (currentX > 30) currentX -= 31;
      wentPast = yOffset;
    }

    result *= trees;
  }

  return result;
}
