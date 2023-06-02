#include "Utilities.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

std::vector<std::string>
Utilities::ReadFileToStringVector(std::string const &filePath) {
  std::vector<std::string> result;

  // Chack if file exists
  if (std::filesystem::exists(filePath)) {
    std::fstream input_file(filePath);
    if (!input_file.is_open()) {
      std::cout << __func__ << ": Error opening File\n";
      return result;
    } else {
      std::string line;
      while (std::getline(input_file, line)) {
        result.push_back(line);
        // std::cout << __func__ << " line " << line << "\n";
      }
    }

  } else {
    std::cout << __func__ << ": File not exists!\n";
  }
  return result;
};

std::string Utilities::ReadFileToString(std::string const &filePath) {
  std::string result;

  // Chack if file exists
  if (std::filesystem::exists(filePath)) {
    std::ifstream input_file(filePath);
    if (!input_file.is_open()) {
      std::cout << __func__ << ": Error opening File\n";
      return result;
    } else {
      std::ostringstream ss;
      ss << input_file.rdbuf();
      result = ss.str();
      // std::cout << "result: " << result << std::endl;
    }

  } else {
    std::cout << __func__ << ": File not exists!\n";
  }
  return result;
}

std::vector<std::string>
Utilities::SplitStringByDelimiter(std::string const &inputStr,
                                  std::string delimiter) {
  std::vector<std::string> result;
  int pos = 0;

  std::string::size_type beg = 0;
  for (auto end = 0; (end = inputStr.find(delimiter, end)) != std::string::npos;
       ++end) {
    result.push_back(inputStr.substr(beg, end - beg));
    beg = end + delimiter.size();
  }

  result.push_back(inputStr.substr(beg));

  return result;
};

std::string Utilities::GetStringBetweenTwoChar(std::string const &inputStr,
                                               const char startChar,
                                               const char endChar) {
  std::string result;

  size_t pos1 = inputStr.find(startChar);
  // Check if index is valid
  if (pos1 != std::string::npos) {
    // Get index position of second quote in string
    size_t pos2 = inputStr.find(endChar, pos1 + 1);
    // Check if index is valid
    if (pos2 != std::string::npos) {
      // Get substring between index positions of two quotes
      result = inputStr.substr(pos1 + 1, pos2 - pos1 - 1);
    }
  }

  return result;
};

std::vector<std::string>
Utilities::ExtractStringPatternRegex(std::string const &inputStr,
                                     std::regex pattern) {
  std::string input = inputStr;
  std::smatch match;

  std::vector<std::string> result;

  while (std::regex_search(input, match, pattern)) {
    result.push_back(match.str(0));
    // suffix to find the rest of the string.
    input = match.suffix().str();
  }

  return result;
};
