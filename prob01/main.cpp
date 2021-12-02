#include <iomanip>
#include <iostream>
#include <string>

#include "minmax.hpp"

int main() {
  int a = 1, b = 10, c = 8, d = 42;
  double w = 3.14, x = 8.25, y = -1.11, z = 13.37;
  std::string cat = "cat", dog = "dog", abc = "abc", xyz = "xyz";

  // get the minimum and maximum of two integer values
  std::cout << "The max of " << a << " and " << b << " is: " << maximum(a, b)
            << std::endl;
  std::cout << "The min of " << c << " and " << d << " is: " << minimum(c, d)
            << std::endl;

  // get the minimum and maximum of two floating point values
  std::cout << std::fixed << std::setprecision(2);
  std::cout << "The max of " << w << " and " << x << " is: " << maximum(w, x)
            << std::endl;
  std::cout << "The min of " << y << " and " << z << " is: " << minimum(y, z)
            << std::endl;

  // get the minimum and maximum of two string values
  std::cout << "The max of \"" << cat << "\" and \"" << dog
            << "\" is: " << maximum(cat, dog) << std::endl;
  std::cout << "The min of \"" << abc << "\" and \"" << xyz
            << "\" is: " << minimum(abc, xyz) << std::endl;

  // clear out the output file
  // note: this is needed because the WriteToFile function appends
  std::ofstream fout;
  fout.open(OUTPUT_FILENAME);
  fout.close();

  // write each of the different data types to a file:
  // integer, floating point, and string
  writeToFile(OUTPUT_FILENAME, a);
  writeToFile(OUTPUT_FILENAME, w);
  writeToFile(OUTPUT_FILENAME, abc);

  return 0;
}
