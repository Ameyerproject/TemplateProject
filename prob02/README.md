# Template Class
In this program, you will be creating a class that utilizes class templates.

Template classes are defined with either `template <class T>` or `template <typename T>` (*class* and *typename* can be used interchangeably in a template definition).

## `pair_template.hpp`
Create a template class called `MyPair`.

All functions for this class will be *inline functions* defined in the `pair_template.hpp` file. There is no corresponding cpp file. This is because the compiler needs to know the implementation of a template class in order to create the actual code with the proper data types (based on the data types in each call to the template class).

Don't forget to add include guards (`#ifndef` `#define` `#endif`) to the header file `pair_template.hpp` in order to be sure the file will be included only once.

### Private Data Members
1. `_value1` which is a `T` object
1. `_value2` which is a `T` object

### Non-Default Constructor
Create a non-default constructor that takes in two `T` objects as parameters and uses these to initialize the values of the private data members.

### Accessors
Create an accessor for each data member, called `getValue1()` and `getValue2()`.

### Display Member Function
Create a member function called `display()` that will display the member variables in the order shown in the output below.
```
    [value1, value2]
```

### Display Reverse Member Function
Create a member function called `displayReverse()` that will display the member variables in reverse order as shown in the output below.
```
    [value2, value1]
```

### Max Value Member Function
Create a member function called `maxValue()` that does not take any parameters, and returns a `T` object. This member function should compare the two member variable values and return the greater value. If the values are equal, you can arbitrarily choose either one to return.

### Min Value Member Function
Create a member function called `minValue()` that does not take any parameters, and returns a `T` object. This member function should compare the two member variable values and return the lesser value. If the values are equal, you can arbitrarily choose either one to return.

### Swap Value Member Function
Create a member function called `swapValue()` that does not take any parameters, nor does it return a value. This function swaps the values of the two member variables.

## `main.cpp`
Complete the `main()` function according to the `TODO` comments in `main.cpp`.

# Unit Test
This lab contains a unit test, which can be run by typing the following commands in the *Terminal* window. You can use the output from the unit tests to help debug any potential bugs in your program.
```
make build
make test
```

# Run Your Program
The `make build` command above creates an executable named `main`. Therefore, you do not need to run `clang++` for this lab. See the sample output below for what your program should print when you run it.
```
./main
```

# Sample Output
```
[3, 5]
[5, 3]
5
3
[5, 3]
[3, 5]
[9.7, 6.4]
[6.4, 9.7]
9.7
6.4
[6.4, 9.7]
[9.7, 6.4]
[a, z]
[z, a]
z
a
[z, a]
[a, z]
```

# Submission checklist
1. Compiled successfully (`make build`)
1. Corrected any compilation logical errors and warning messages
1. Ran the driver to ensure proper output (`./main`)
1. Ensured no errors on the unit test (`make test`)
