# Template Functions
This lab uses template functions to reuse common algorithms for different data types.

Template functions are defined with either `template <class T>` or `template <typename T>` (*class* and *typename* can be used interchangeably in a template function definition).

## `minmax.hpp`
You will place the functions in the `minmax.hpp` file.

There is no corresponding cpp file. This is because the compiler needs to know the implementation of a template function in order to create the actual code with the proper data types (based on the data types in each call to the template function).

### Minimum Value
Create a template function called `minimum()` that accepts two T objects. Define these parameters to be constant references to T objects. This function should return the smaller of the two objects.

*Hint: use the `<` operator to determine which object is smaller. This function assumes operator< has been defined for the parameter data type.*

### Maximum Value
Create a template function called `maximum()` that accepts two T objects. Define these parameters to be constant references to T objects. This function should return the larger of the two objects.

*Hint: use the `>` operator to determine which object is smaller. This function assumes operator> has been defined for the parameter data type.*

### Write to a File
Create a function called `writeToFile()` that accepts two parameters, a `std::string` and a T object, in that order. Define both parameters to be constant reference parameters.

The first parameter represents the name of the file to write to. Open that file in append mode, write the second parameter to the file, and then close the file.

*Hint: to open a file in "append" mode, you can use the overloaded function "open" that takes two parameters: the file name followed by the file mode. You can use `std::ios_base::app` for the file mode. Opening a file in append mode creates the file if it doesn't already exist, or writes to the end of the file if it already exists.*

## `main.cpp`
The `main()` function has been provided for you. Notice how we can call the same functions, passing in parameters of different data types.

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
The max of 1 and 10 is: 10
The min of 8 and 42 is: 8
The max of 3.14 and 8.25 is: 8.25
The min of -1.11 and 13.37 is: -1.11
The max of "cat" and "dog" is: dog
The min of "abc" and "xyz" is: abc
```

# Output File
The output file should contain the following text. You can view this either by opening the file "temp.txt" in whatever editor you use for your code, or by typing `cat temp.txt` at the command prompt.
```
1
3.14
abc
```
