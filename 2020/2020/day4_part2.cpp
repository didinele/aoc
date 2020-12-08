#include "main.h"
#include <fstream>
#include <string>
#include <unordered_set>

class Passport
{
private:
  std::string raw;

  int byr;
  int iyr;
  int eyr;
  std::string hgt;
  std::string hcl;
  std::string ecl;
  std::string pid;

  bool input_is_valid() {
    using std::string;
    std::string value = this->raw;
    return value.find("byr:") != string::npos
      && value.find("iyr:") != string::npos
      && value.find("eyr:") != string::npos
      && value.find("hgt:") != string::npos
      && value.find("hcl:") != string::npos
      && value.find("ecl:") != string::npos
      && value.find("pid:") != string::npos;
  }

  void update() {
    std::string construct;
    std::string field;
    for (char c : (this->raw + ' ')) {
      if (c == ':') {
        field = construct;
        construct = "";
      }
      else if (c == ' ') {
        if (field == "byr") this->byr = std::stoi(construct);
        else if (field == "iyr") this->iyr = std::stoi(construct);
        else if (field == "eyr") this->eyr = std::stoi(construct);
        else if (field == "hgt") this->hgt = construct;
        else if (field == "hcl") this->hcl = construct;
        else if (field == "ecl") this->ecl = construct;
        else if (field == "pid") this->pid = construct;
        construct = "";
      }
      else {
        construct += c;
      }
    }
  }

public:
  int get_raw_length() {
    return this->raw.length();
  }

  Passport& operator+=(const std::string& str) {
    this->raw += str;
    if (this->input_is_valid()) this->update();
    return *this;
  }

  bool isValid() {
    std::string h_unit = this->hgt.length() > 2 ? this->hgt.substr(this->hgt.length() - 2, 2) : "";
    bool h_unit_valid = h_unit == "cm" || h_unit == "in";
    int h = h_unit_valid ? std::stoi(this->hgt.substr(0, this->hgt.length() - 2)) : 0;

    bool h_valid = h_unit_valid
      ? (
        h_unit == "cm"
          ? (h >= 150 && h <= 193)
          : (h >= 59 && h <= 76)
      )
      : false;

    bool hcl_valid = this->hcl.length() == 7;
    std::unordered_set<char> valid_chars({ 'a', 'b', 'c', 'd', 'e', 'f', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' });

    if (hcl_valid) {
      for (char c : this->hcl.substr(1, this->hcl.size() - 1)) {
        if (valid_chars.find(c) == valid_chars.end()) {
          hcl_valid = false;
          break;
        }
      }
    }

    return this->input_is_valid()
      && (this->byr >= 1920 && this->byr <= 2002)
      && (this->iyr >= 2010 && this->iyr <= 2020)
      && (this->eyr >= 2020 && this->eyr <= 2030)
      && h_valid
      && hcl_valid
      && (this->ecl == "amb" || this->ecl == "blu" || this->ecl == "brn" || this->ecl == "gry" || this->ecl == "grn" || this->ecl == "hzl" || this->ecl == "oth")
      && (this->pid.length() == 9);
  }
};

long long int solution_4_2(void)
{
  std::ifstream infile("4.txt");

  std::string line;
  Passport passport;

  int valid = 0;

  while (std::getline(infile, line)) {
    if (line == "") {
      if (passport.isValid()) valid++;
      passport = Passport();
      continue;
    }

    passport += (passport.get_raw_length() == 0 ? "" : " ") + line;
  }

  if (passport.isValid()) valid++;

  return valid;
}
