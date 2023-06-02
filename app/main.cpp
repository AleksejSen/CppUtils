#include "Utilities.h"
#include <iostream>

int main(int argc, char **argv) {

  std::string file = "/home/alex/Documents/SW_Dew/Cpp/CodeTest/build.sh";
  std::string raw_data = "Monday;#%Tuesday;#%Wedesday;#%Thursday";
  std::string tag = "\"SomeTag\"";
  std::string regInput("My GeeksforGeeks is my GeeksforGeeks33 none of your "
                       "GeeksforGeeks and more and more GeeksforGeeks and more "
                       "and more GeeksforGeeksand more and more GeeksforGeeks");

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

  std::cout << "Tag extract: "
            << Utilities::GetStringBetweenTwoChar(tag, '\"', '\"') << "\n";

  std::regex r("GeeksforGeeks33");
  auto regOut = Utilities::ExtractStringPatternRegex(regInput, r);

  for (auto rg : regOut) {
    std::cout << "regex result: " << rg << std::endl;
  }

  return 0;
}
