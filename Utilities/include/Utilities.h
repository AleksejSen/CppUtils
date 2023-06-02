#ifndef UTILITIES_H_
#define UTILITIES_H_
#include <iostream>
#include <regex>
#include <string>
#include <vector>

class Utilities {
private:
  /* data */
public:
  static std::vector<std::string>
  ReadFileToStringVector(std::string const &filePath);

  static std::string ReadFileToString(std::string const &filePath);

  static std::vector<std::string>
  SplitStringByDelimiter(std::string const &inputStr, std::string delimiter);

  static std::string GetStringBetweenTwoChar(std::string const &inputStr,
                                             const char startChar,
                                             const char endChar);
  static std::vector<std::string>
  ExtractStringPatternRegex(std::string const &inputStr, std::regex pattern);
};

#endif
