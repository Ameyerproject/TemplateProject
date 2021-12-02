#include "pair_template.hpp"

int main()
{
  // Create an instance of `MyPair` object called `p1` using `int`
  // and passing in values `3` and `5`
  MyPair<int> p1(3, 5);

  // using the `p1` object, do the following:
  // Call the Display method followed by a newline character
  p1.display();
  std::cout << '\n';

  // Call the DisplayReverse method
  p1.displayReverse();
  std::cout << '\n';
  // Call the MaxValue method and print the value
  std::cout << p1.maxValue() << '\n';
  // Call the MinValue method and print the value
  std::cout << p1.minValue() << '\n';

  // Call the SwapValue method
  p1.swapValue();

  // Call the Display method
  p1.display();
  std::cout << '\n';

  // Call the DisplayReverse method
  p1.displayReverse();
  std::cout << '\n';



  // Create an instance of `MyPair` object called `p2` using `double`
  // and passing in the values `9.7` and `6.4`
  MyPair<double> p2(9.7, 6.4);


  // *Start using `p2` to call methods*
  // Call the Display method
  p2.display();
  std::cout << '\n';

  // Call the DisplayReverse method
  p2.displayReverse();
  std::cout << '\n';
  // Call the MaxValue method and print the value
  std::cout << p2.maxValue() << '\n';
  // Call the MinValue method and print the value
  std::cout << p2.minValue() << '\n';;

  // Call the SwapValue method
  p2.swapValue();
  // Call the Display method
  p2.display();
  std::cout << '\n';

  // Call the DisplayReverse method
  p2.displayReverse();
  std::cout << '\n';



  // Create an instance of `MyPair` object called `p3` using `char`
  // and passing in the values `a` and `z`
  MyPair<char> p3('a', 'z');


  // *Start using `p3` to call methods*
  // Call the Display method
  p3.display();
  std::cout << '\n';

  // Call the DisplayReverse method
  p3.displayReverse();
  std::cout << '\n';
  // Call the MaxValue method and print the value
  std::cout << p3.maxValue() << '\n';
  // Call the MinValue method and print the value
  std::cout << p3.minValue() << '\n';

  // Call the SwapValue method
  p3.swapValue();
  // Call the Display method

  p3.display();
  std::cout << '\n';

  // Call the DisplayReverse method
  p3.displayReverse();
  std::cout << '\n';

  return 0;
}
