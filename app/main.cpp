#include "Utilities.h"
#include <iostream>

int main(int argc, char **argv) {

  std::string file = "/home/alex/Documents/SW_Dew/Cpp/CodeTest/build.sh";

  auto data = Utilities::ReadFileToStringVector(file);

  for (auto s : data) {
    std::cout << "data line: " << s << "\n";
  }
  std::cout << ".........................\n";

  std::string data2 = Utilities::ReadFileToString(file);

  std::cout << "Data2:\n" << data2;

  return 0;
}
