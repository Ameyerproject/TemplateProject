#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../cppaudit/gtest_ext.h"
#include "../../pair_template.hpp"

TEST(Pair, PublicMethodsPresent) {
  MyPair<int> your_pair(5, 3);
  your_pair.swapValue();
  your_pair.maxValue();
  your_pair.minValue();
  SIMULATE_SIO("", {
    your_pair.display();
    your_pair.displayReverse();
  }, {})
}

TEST(Pair, Constructor) {
  MyPair<char> your_pair_char('a', 'c');
  MyPair<int> your_pair_int(2, 6);
  MyPair<std::string> your_pair_string("Hello", "Goodbye");
}

TEST(PairInt, Accessors) {
  MyPair<int> your_pair(2, 6);
  ASSERT_EQ(your_pair.getValue1(), 2)
      << "The accessor should return the value of value1, 2.";
  ASSERT_EQ(your_pair.getValue2(), 6)
      << "The accessor should return the value of value2, 6.";
}

TEST(PairChar, Accessors) {
  MyPair<char> your_pair('a', 'c');
  ASSERT_EQ(your_pair.getValue1(), 'a')
      << "The accessor should return the value of value1, 'a'.";
  ASSERT_EQ(your_pair.getValue2(), 'c')
      << "The accessor should return the value of value2, 'c'.";
}

TEST(PairDouble, Accessors) {
  double v1 = 11.1, v2 = 9.9;
  MyPair<double> your_pair(v1, v2);
  ASSERT_EQ(your_pair.getValue1(), v1)
      << "The function should return " << v1 << " given the pair [" << v1 << ", " << v2 << "]";
  ASSERT_EQ(your_pair.getValue2(), v2)
      << "The function should return " << v2 << " given the pair [" << v1 << ", " << v2 << "]";
}

TEST(PairString, Accessors) {
  MyPair<std::string> your_pair("Hello", "Goodbye");
  ASSERT_EQ(your_pair.getValue1(), "Hello")
      << "The accessor should return the value of value1, Hello.";
  ASSERT_EQ(your_pair.getValue2(), "Goodbye")
      << "The accessor should return the value of value2, Goodbye.";
}

TEST(Pair, Display) {
  MyPair<double> your_pair(5.5, 4.4);
  SIMULATE_SIO(
      "", { your_pair.display(); }, { ASSERT_EQ(your_output, "[5.5, 4.4]"); })
}

TEST(Pair, DisplayReverse) {
  MyPair<std::string> your_pair("Hello", "Goodbye");
  SIMULATE_SIO(
      "", { your_pair.displayReverse(); },
      { ASSERT_EQ(your_output, "[Goodbye, Hello]"); })
}

TEST(PairInt, MaxValue1) {
  MyPair<int> your_pair(1, 9);
  ASSERT_EQ(your_pair.maxValue(), 9)
      << "The function should return 9 given the pair [1, 9]";
}

TEST(PairInt, MaxValue2) {
  MyPair<int> your_pair(9, 1);
  ASSERT_EQ(your_pair.maxValue(), 9)
      << "The function should return 9 given the pair [9, 1]";
}

TEST(PairDouble, MinValue1) {
  double v1 = 1.1, v2 = 9.9;
  MyPair<double> your_pair(v1, v2);
  ASSERT_EQ(your_pair.minValue(), v1)
      << "The function should return " << v1 << " given the pair [" << v1 << ", " << v2 << "]";
}

TEST(PairDouble, MinValue2) {
  double v1 = 11.1, v2 = 9.9;
  MyPair<double> your_pair(v1, v2);
  ASSERT_EQ(your_pair.minValue(), v2)
      << "The function should return " << v2 << " given the pair [" << v1 << ", " << v2 << "]";
}

TEST(PairDouble, MaxValue1) {
  double v1 = 11.1, v2 = 9.9;
  MyPair<double> your_pair(v1, v2);
  ASSERT_EQ(your_pair.maxValue(), v1)
      << "The function should return " << v1 << " given the pair [" << v1 << ", " << v2 << "]";
}

TEST(PairDouble, MaxValue2) {
  double v1 = 1.1, v2 = 9.9;
  MyPair<double> your_pair(v1, v2);
  ASSERT_EQ(your_pair.maxValue(), v2)
      << "The function should return " << v2 << " given the pair [" << v1 << ", " << v2 << "]";
}

TEST(PairChar, MaxValue1) {
  char v1 = 'c', v2 = 'a';
  MyPair<char> your_pair(v1, v2);
  ASSERT_EQ(your_pair.maxValue(), v1)
      << "The function should return " << v1 << " given the pair [" << v1 << ", " << v2 << "]";
}

TEST(PairChar, MaxValue2) {
  char v1 = 'a', v2 = 'b';
  MyPair<char> your_pair(v1, v2);
  ASSERT_EQ(your_pair.maxValue(), v2)
      << "The function should return " << v2 << " given the pair [" << v1 << ", " << v2 << "]";
}

TEST(PairString, MaxValue1) {
  MyPair<std::string> your_pair("Sea", "Sew");
  ASSERT_EQ(your_pair.maxValue(), "Sew")
      << "The function should return Sew given the pair [Sea, Sew]";
}

TEST(PairString, MaxValue2) {
  MyPair<std::string> your_pair("Sew", "Sea");
  ASSERT_EQ(your_pair.maxValue(), "Sew")
      << "The function should return Sew given the pair [Sew, Sea]";
}

TEST(PairInt, Swap) {
  MyPair<int> your_pair(26, 53);
  your_pair.swapValue();
  ASSERT_EQ(your_pair.getValue1(), 53)
      << "The function should return 53 given the pair [26, 53] after swapping";
  ASSERT_EQ(your_pair.getValue2(), 26)
      << "The function should return 26 given the pair [26, 53] after swapping";
}

TEST(PairDouble, Swap) {
  double v1 = 2.6, v2 = 5.3;
  MyPair<double> your_pair(v1, v2);
  your_pair.swapValue();
  ASSERT_EQ(your_pair.getValue1(), v2)
    << "The function should return " << v2 << " given the pair [" << v1 << ", " << v2 << "] after swapping";
  ASSERT_EQ(your_pair.getValue2(), v1)
    << "The function should return " << v1 << " given the pair [" << v1 << ", " << v2 << "] after swapping";
}

TEST(PairChar, Swap) {
  char v1 = 'c', v2 = 'q';
  MyPair<char> your_pair(v1, v2);
  your_pair.swapValue();
  ASSERT_EQ(your_pair.getValue1(), v2)
    << "The function should return " << v2 << " given the pair [" << v1 << ", " << v2 << "] after swapping";
  ASSERT_EQ(your_pair.getValue2(), v1)
    << "The function should return " << v1 << " given the pair [" << v1 << ", " << v2 << "] after swapping";
}

TEST(PairString, Swap) {
  MyPair<std::string> your_pair("Sew", "Sea");
  your_pair.swapValue();
  ASSERT_EQ(your_pair.getValue1(), "Sea")
      << "The function should return \"Sea\" given the pair [\"Sew\", \"Sea\"] after swapping";
  ASSERT_EQ(your_pair.getValue2(), "Sew")
      << "The function should return \"Sew\" given the pair [\"Sew\", \"Sea\"] after swapping";
}

TEST(Driver, Output) {
  std::string unittest_output =
      "[3, 5]\n"
      "[5, 3]\n"
      "5\n"
      "3\n"
      "[5, 3]\n"
      "[3, 5]\n"
      "[9.7, 6.4]\n"
      "[6.4, 9.7]\n"
      "9.7\n"
      "6.4\n"
      "[6.4, 9.7]\n"
      "[9.7, 6.4]\n"
      "[a, z]\n"
      "[z, a]\n"
      "z\n"
      "a\n"
      "[z, a]\n"
      "[a, z]\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECEQ("main", "", unittest_output);
  });
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
