#include "main.h"
#include <fstream>
#include <string>

long long int solution_2_2(void)
{
  std::ifstream infile("2.txt");
  std::string line;
  int valid = 0;

  // Each line will have 3 individual "components", so when i reaches 3, we know we've reached the next input
  int i = 0;

  int positions[2];
  bool former = false;
  bool latter = false;
  char letter;

  while (infile >> line) {
    // We're dealing with min-max pairs.
    if (i == 0) {
      std::string construct;
      for (char c : line) {
        if (c == '-') {
          positions[0] = std::stoi(construct);
          construct = "";
        }
        else {
          construct += c;
        }
      }

      positions[1] = std::stoi(construct);
      i++;
    }
    else if (i == 1) {
      letter = line[0];
      i++;
    }
    else if (i == 2) {
      char former_char = line[positions[0] - 1];
      char latter_char = line[positions[1] - 1];

      if (
        (former_char == letter && latter_char != letter) ||
        (former_char != letter && latter_char == letter)
      ) valid++;

      i = 0;
    }
  }

  return valid;
}
