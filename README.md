#  Lab Exercise 11 Objectives
1. Templates

# Additional Reading
Chapter 16 of the course textbook

# Instructions
Follow the README files for each problem assigned (e.g., prob01, prob02, prob03). If you have questions let your instructor know. You are also welcome to consult your classmates.

# Code Evaluation
*Note:* the explanations of all commands listed below are detailed in **labex00**. Refer to the README file in labex00, if needed.

1. Get a copy of the lab exercise from GitHub, and change directory into prob01, and open `main.cpp` for editing in atom.

   ```
   git clone URL

   cd labex01-USERNAME/prob01

   atom main.cpp
   ```

1. Compile your program.

   ```
   clang++ -std=c++17 *.cpp -o main
   ```

   For lab assignments that include a *Makefile*, if that Makefile includes a *build* rule, you have the option of compiling your lab using the make build command instead of the *clang* command.

   ```
   make build
   ```

1. Run your program.

   ```
   ./main
   ```

1. For lab assignments that include a *Makefile* plus either a *test* directory or a *tools* directory, you can run the unit test by typing the following:

   ```
   make test
   ```

   This runs your code through several unit tests in order to check whether your code produces the desired output based on various input values.

   You can also check the style and format of your code by typing the following:

   ```
   make stylecheck
   make formatcheck
   ```

   Note that the formatcheck is sometimes more rigorous than the coding standards we will be following this semester. Therefore, you can use it as a guide, but you do not need to follow its suggestions that don't match our style guide this semester. If you have any questions regarding the output and which of the suggestions should be followed, please feel free to ask your instructor.

   You can run all three of these (the unit test, style check, and format check) using the *all* option, as follows:

   ```
   make all
   ```

   If you get an error telling you that it couldn't find "stddef.h" then try installing the latest clang libraries by typing the following. After typing this, try running the "make" utility again.

   ```
   apt install clang -y
   ```

1. When you want to move to another problem, you need to go back up to the parent folder and navigate into the next problem. For example:

   ```
   cd ../prob02
   ```

# Submission
1. To upload your code to GitHub you will run the following 3 commands. You will replace the text *"Description of your code changes"* with an actual description of what you are checking in.
   - If you happen to get stuck in the *nano* editor, press <kbd>Ctrl</kbd> + <kbd>x</kbd> to exit. Press <kbd>Y</kbd> to confirm that you want to make changes and then press <kbd>Enter</kbd>.

   ```
   git add .
   git commit -m "Please type a brief description of your code changes"
   git push
   ```

1. If it asks you to configure global variables for an email and name, just copy the commands it provides but replace the dummy text with your email and GitHub username. When you're done, make sure you `git commit` your repository again.

   ```
   git config --global user.email "tuffy@csu.fullerton.edu"
   git config --global user.name "Tuffy Titan"
   ```

1. Once you have pushed your changes to GitHub, double check that your local repository is clean. The following should report: **Your branch is up to date with 'origin/master'**

   ```
   git status
   ```

1. Go back to the GitHub Website and refresh the page to see that your changes are there.
