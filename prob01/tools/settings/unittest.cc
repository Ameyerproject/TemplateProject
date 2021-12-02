#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <cmath>
#include <string>
#include <fstream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../cppaudit/gtest_ext.h"
#include "../../minmax.hpp"

using ::testing::HasSubstr;
using ::testing::MatchesRegex;

struct FileCreation : public UnitTestFileManager {
  FileCreation() : UnitTestFileManager("create_file.txt") {}
};

int fileSize(const std::string & filename){
  std::ifstream in_file;
  in_file.open(filename, std::ios_base::binary);
  if (!in_file)
    return -1;
  in_file.seekg(0, std::ios_base::end);
  int size = in_file.tellg();
  in_file.close();
  return size;
}

std::string getUniqueName(){
  static bool init = false;
  if (!init) {
    srand(time(NULL));
    init = true;
  }
  std::string filename;
  std::ifstream in_file;
  while (true) {
    int r = rand() % 1000;
    filename = "tmp" + std::to_string(r) + ".txt";
    in_file.open(filename);
    if (!in_file)
      break;
    in_file.close();
  }
  return filename;
}

TEST(Minimum, MinFirst) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(minimum(9, 10), 9);
  });
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(minimum(-2.33, -3.67), -3.67);
  });
  std::string unittest_output = "def";
  std::string your_string1 = "def";
  std::string your_string2 = "ghi";
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(minimum(your_string1, your_string2), unittest_output) << "   Input: your_string 1 = " << your_string1 << " your_string 2 = " << your_string2;
  });
}

TEST(Minimum, MinSecond) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(minimum(9, 7), 7);
  });
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(minimum(-1.33, -3.67), -3.67);
  });
  std::string unittest_output = "def";
  std::string your_string1 = "ghi";
  std::string your_string2 = "def";
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(minimum(your_string1, your_string2), unittest_output) << "   Input: your_string 1 = " << your_string1 << " your_string 2 = " << your_string2;
  });
}

TEST(Minimum, EqualTo) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(minimum(3, 3), 3);
  });
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(minimum(-8.88,-8.88), -8.88);
  });
  std::string unittest_output = "jkl";
  std::string your_string1 = "jkl";
  std::string your_string2 = "jkl";
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(minimum(your_string1, your_string2), unittest_output) << "   Input: your_string 1 = " << your_string1 << " your_string 2 = " << your_string2;
  });
}

TEST(Maximum, MaxFirst) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(maximum(590, 442), 590);
  });
  ASSERT_DURATION_LE(3, {
   ASSERT_EQ(maximum(33.7, 1.23), 33.7);
  });
  std::string unittest_output = "zzz";
  std::string your_string1 = "zzz";
  std::string your_string2 = "xyz";
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(maximum(your_string1, your_string2), unittest_output) << "   Input: your_string 1 = " << your_string1 << " your_string 2 = " << your_string2;
  });
}

TEST(Maximum, MaxSecond) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(maximum(90, 442), 442);
  });
  ASSERT_DURATION_LE(3, {
   ASSERT_EQ(maximum(33.7, 41.23), 41.23);
  });
  std::string unittest_output = "xyz";
  std::string your_string1 = "abc";
  std::string your_string2 = "xyz";
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(maximum(your_string1, your_string2), unittest_output) << "   Input: your_string 1 = " << your_string1 << " your_string 2 = " << your_string2;
  });
}

TEST(Maximum, EqualTo) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(maximum(777, 777), 777);
  });
  ASSERT_DURATION_LE(3, {
   ASSERT_EQ(maximum(155.5, 155.5), 155.5);
  });
  std::string unittest_output = "def";
  std::string your_string1 = "def";
  std::string your_string2 = "def";
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(maximum(your_string1, your_string2), unittest_output) << "   Input: your_string 1 = " << your_string1 << " your_string 2 = " << your_string2;
  });
}

TEST(WriteToFile, WriteData) {
  std::string filename = getUniqueName();
  std::string user_input = "something";
  writeToFile(filename, user_input); // create
  std::ifstream user_file;
  user_file.open(filename);
  std::string line1;
  std::getline(user_file, line1);
  user_file.close();
  remove(filename.c_str());
  ASSERT_TRUE(line1 == user_input)
      << "      Your program should write parameter#2 to the file named by parameter#1.";
}

TEST(WriteToFile, CreateFile) {
  std::string filename = getUniqueName();
  std::string user_input = "something";
  writeToFile(filename, user_input); // test
  std::ifstream user_file;
  user_file.open(filename);
  ASSERT_TRUE(user_file.good())
      << "      Your program should create the file if it doesn't exist.";
  user_file.close();
  remove(filename.c_str());
}

TEST(WriteToFile, AppendFile) {
  std::string filename = getUniqueName();
  std::string user_input = "something";
  writeToFile(filename, user_input); // create
  int start_size = fileSize(filename);
  writeToFile(filename, user_input); // test
  int end_size = fileSize(filename);
  remove(filename.c_str());
  ASSERT_TRUE(start_size > 0 && start_size < end_size)
      << "      Your program should append to the file if it already exists.";
}

TEST(Main, OutputFormat) {
  std::ostringstream s, input;
  s << "The max of 1 and 10 is: 10" << std::endl;
  s << "The min of 8 and 42 is: 8" << std::endl;
  s << "The max of 3.14 and 8.25 is: 8.25" << std::endl;
  s << "The min of -1.11 and 13.37 is: -1.11" << std::endl;
  s << "The max of \"cat\" and \"dog\" is: dog" << std::endl;
  s << "The min of \"abc\" and \"xyz\" is: abc" << std::endl;
  input << "";
  std::string unittest_input = input.str(), unittest_output = s.str();
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", unittest_input, unittest_output);
  });
}

TEST(Main, FileOutput) {
  remove(OUTPUT_FILENAME.c_str());
  int start_size = fileSize(OUTPUT_FILENAME);
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECEXIT("main", "", 2);
  });
  int end_size = fileSize(OUTPUT_FILENAME);
  //std::cout << start_size << ' ' << end_size << ' ' << OUTPUT_FILENAME << std::endl;
  ASSERT_TRUE(start_size < 0 && end_size > 0)
      << "      Your program should write to the file named by the constant OUTPUT_FILENAME.";
}

TEST(Main, FileFormat) {
  int start_size = fileSize(OUTPUT_FILENAME);
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECEXIT("main", "", 2);
  });
  int end_size = fileSize(OUTPUT_FILENAME);
  //std::cout << start_size << ' ' << end_size << ' ' << OUTPUT_FILENAME << std::endl;
  ASSERT_TRUE(start_size == end_size)
      << "      Your program should write to the file named by the constant OUTPUT_FILENAME.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  bool skip = true;
  for (int i = 0; i < argc; i++) {
    if (std::string(argv[i]) == "--noskip") {
      skip = false;
    }
  }
  if (skip) {
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  }
  return RUN_ALL_TESTS();
}
