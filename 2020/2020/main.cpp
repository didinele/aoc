#include <iostream>
#include <sstream>
#include "main.h"

typedef long long int(*Solution)();

int main(int argc, char* argv[])
{
  Solution solutions[31][2] = {
    { solution_1_1, solution_1_2 },
    { solution_2_1, solution_2_2 },
    { solution_3_1, solution_3_2 },
    { solution_4_1, solution_4_2 }
  };

  if (argc < 3) {
    std::cout << "Please provide a day number and the part of the challange that you want to run" << std::endl;
    return 1;
  }

  std::istringstream day_s(argv[1]);
  int day;
  if (!(day_s >> day)) {
    std::cout << "Invalid number: " << argv[1] << std::endl;
    return 1;
  }
  else if (!day_s.eof()) {
    std::cout << "Trailing characters after number: " << argv[1] << std::endl;
    return 1;
  }
  else if (day < 1 || day > 31) {
    std::cout << "Day not in rage, please provide a value from 1 to 31" << std::endl;
    return 1;
  }

  std::istringstream part_s(argv[2]);
  int part;
  if (!(part_s >> part)) {
    std::cout << "Invalid number: " << argv[1] << std::endl;
    return 1;
  }
  else if (!part_s.eof()) {
    std::cout << "Trailing characters after number: " << argv[1] << std::endl;
    return 1;
  }
  else if (part != 1 && part != 2) {
    std::cout << part << std::endl;
    std::cout << "Please specify a valid part (1 or 2)." << std::endl;
    return 1;
  }

  std::cout << solutions[day - 1][part - 1]() << std::endl;
}
