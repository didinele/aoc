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
    int x_off_set = slope[0];
    int y_off_set = slope[1];

    long long int trees = 0;
    int current_x = 0;
    int went_past = 0;

    std::ifstream infile("3.txt");
    std::string line;
    while (infile >> line) {
      if (went_past > 1) {
        went_past--;
        continue;
      }

      if (line[current_x] == '#') trees++;
      current_x += x_off_set;
      if (current_x > 30) current_x -= 31;
      went_past = y_off_set;
    }

    result *= trees;
  }

  return result;
}
