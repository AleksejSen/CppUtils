#include "Utilities.h"
#include <filesystem>
#include <fstream>
#include <iostream>

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
        std::cout << __func__ << " line " << line << "\n";
      }
    }

  } else {
    std::cout << __func__ << ": File not exists!\n";
  }
  return result;
};

// std::string file_path = "example.txt"; // Replace with your file path
// std::ifstream input_file(file_path);

// // Check if the file is opened successfully
// if (.input_file.is_open()) {
//   std::cerr << "Error opening the file: " << file_path << std::endl;
//   return 1;
// }

// std::string line;
// while (std::getline(input_file, line)) {
//   std::cout << line << std::endl; // Process each line, e.g., print it
// }

// input_file.close();
// return 0;