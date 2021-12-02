#ifndef __MINMAX_HPP__
#define __MINMAX_HPP__

#include <fstream>

//---------------------------
// constants
//---------------------------

const std::string OUTPUT_FILENAME = "temp.txt";

//---------------------------
// global template functions
//---------------------------

template <typename T>
T minimum(const T& a, const T& b) {
  T min = a < b ? a : b;
  return min;
}

template <typename T>
T maximum(const T& a, const T& b) {
  T max = a > b ? a : b;
  return max;
}

template <typename T>
void writeToFile(const std::string& filename, const T& object) {
  std::fstream tempFile(filename, std::ios_base::app);
  tempFile << object << '\n';
}

#endif
