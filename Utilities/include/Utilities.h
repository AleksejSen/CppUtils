#ifndef UTILITIES_H_
#define UTILITIES_H_
#include <iostream>
#include <string>
#include <vector>

class Utilities {
private:
  /* data */
public:
  static std::vector<std::string>
  ReadFileToStringVector(std::string const &filePath);
};

#endif
