#include "main.h"
#include <fstream>
#include <string>

static bool check(std::string& input) {
  using std::string;
  return input.find("byr:") != string::npos
    && input.find("iyr:") != string::npos
    && input.find("eyr:") != string::npos
    && input.find("hgt:") != string::npos
    && input.find("hcl:") != string::npos
    && input.find("ecl:") != string::npos
    && input.find("pid:") != string::npos;
}

long long int solution_4_1(void)
{
  std::ifstream infile("4.txt");

  std::string line;
  std::string input;

  int valid = 0;

  while (std::getline(infile, line)) {
    if (line == "") {
      if (check(input)) valid++;
      input = "";
      continue;
    }

    input += ' ' + line;
  }

  if (input.length() && check(input)) valid++;

  return valid; 
}
