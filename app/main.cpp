#include "Utilities.h"
#include <iostream>

int main(int argc, char **argv) {

  std::string file = "/home/alex/Documents/SW_Dew/Cpp/CodeTest/CMakeLists.txt";

  auto data = Utilities::ReadFileToStringVector(file);

  return 0;
}
