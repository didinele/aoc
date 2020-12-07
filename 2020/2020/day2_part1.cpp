#include "main.h"
#include <fstream>
#include <string>

long long int solution_2_1(void)
{
  std::ifstream infile("2.txt");
  std::string line;
  int valid = 0;

  // Each line will have 3 individual "components", so when i reaches 3, we know we've reached the next input
  int i = 0;

  int min;
  int max;
  char letter;
  int count = 0;

  while (infile >> line) {
    // We're dealing with min-max pairs.
    if (i == 0) {
      std::string construct;
      for (char c : line) {
        if (c == '-') {
          min = std::stoi(construct);
          construct = "";
        }
        else {
          construct += c;
        }
      }

      max = std::stoi(construct);
      i++;
    }
    else if (i == 1) {
      letter = line[0];
      i++;
    }
    else if (i == 2) {
      for (char c : line) {
        if (c == letter) count++;
      }

      if (count >= min && count <= max) valid++;

      i = 0;
      count = 0;
    }
  }

  return valid;
}
