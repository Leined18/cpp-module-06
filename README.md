# C++ Exercises

This project contains a series of C++ exercises designed to help you practice and improve your programming skills. Each exercise is contained within its own directory, following a consistent structure.

## Directory Structure

- **ex00**: Contains the first exercise.
  - **inc**: Header files for exercise 00.
  - **src**: Source files for exercise 00.
  - **obj**: Directory for object files generated during compilation.
  - **Makefile**: Build instructions for exercise 00.

- **ex01**: Contains the second exercise.
  - **inc**: Header files for exercise 01.
  - **src**: Source files for exercise 01.
  - **obj**: Directory for object files generated during compilation.
  - **Makefile**: Build instructions for exercise 01.

- **ex02**: Contains the third exercise.
  - **inc**: Header files for exercise 02.
  - **src**: Source files for exercise 02.
  - **obj**: Directory for object files generated during compilation.
  - **Makefile**: Build instructions for exercise 02.

- **ex03**: Contains the fourth exercise.
  - **inc**: Header files for exercise 03.
  - **src**: Source files for exercise 03.
  - **obj**: Directory for object files generated during compilation.
  - **Makefile**: Build instructions for exercise 03.

## Compilation Instructions

Each exercise can be compiled using the provided Makefile located in its respective directory. To compile an exercise, navigate to the exercise directory and run:

```
make
```

To clean up the object files, you can run:

```
make clean
```

## Flags Used

The following compilation flags are used in the Makefiles:

- `-Werror`: Treat warnings as errors.
- `-Wextra`: Enable additional warnings.
- `-Wall`: Enable all standard warnings.
- `-std=c++98`: Use the C++98 standard.
- `-fsanitize=address`: Enable address sanitization for detecting memory errors.

Feel free to explore each exercise and modify the code as you see fit! Happy coding!