#include "Utilities.h"
#include <iostream>

int main(int argc, char **argv) {

  std::string file = "/home/alex/Documents/SW_Dew/Cpp/CodeTest/build.sh";
  std::string raw_data = "Monday;#%Tuesday;#%Wedesday;#%Thursday";
  auto data = Utilities::ReadFileToStringVector(file);

  for (auto s : data) {
    std::cout << "data line: " << s << "\n";
  }
  std::cout << ".........................\n";

  std::string data2 = Utilities::ReadFileToString(file);

  std::cout << "Data2:\n" << data2;

  auto clean_data = Utilities::SplitStringByDelimiter(raw_data, ";#%");

  for (auto d : clean_data) {
    std::cout << "Clan data: " << d << "\n";
  }

  return 0;
}
