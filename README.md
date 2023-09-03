# Chessboard GUI using Qt

This is a simple Qt application that creates a chessboard GUI with brown and light brown squares. You can use this as a starting point to build a chess game or any other application that requires a chessboard-like interface.

## Prerequisites

- CMake (Version 3.2 or higher)
- Qt 5 (Widgets component)

## Building the Application

1. Create a build directory (e.g., `build`) in the root of this project.
2. Open a terminal and navigate to the build directory.
3. Run CMake to configure the project and generate build files:

```
cmake ..
```
Build the application using a build tool (e.g., make on Linux):

```
make
```
Run the application:

```
./test_main
```

## Directory Structure
test: Contains the source code for the chessboard GUI.
CMakeLists.txt: The root CMake configuration file.
test/CMakeLists.txt: CMake configuration for the test application.
## Cleaning
You can clean the build files using the following commands:

### Clean the test application build:

```
make clean_test
```
### Clean all build files (including test):
```
make clean_all
```
## License
This project is licensed under the MIT License - see the LICENSE file for details.
