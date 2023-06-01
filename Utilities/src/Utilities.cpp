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