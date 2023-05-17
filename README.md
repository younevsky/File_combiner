# File Combiner

This C++ program combines all `.txt` files in a given input folder into a single output file. The input folder must be in the same directory as the executable. The program is built using C++17.

## Requirements

- Compiler with C++17 support (e.g., GCC 7 or later, Clang 5 or later, MSVC 19.14 or later)
- CMake 3.8 or later (optional, for building using CMake)
- Filesystem library support (C++17)

## Compilation (make sure you have GCC compiler installed)

### - Bash

```
$ g++ -o combiner combiner.cpp
```
### - Windows
```
$ g++ -o combiner.exe combiner.cpp
```


## Execution
After compiling, run the program as follows:

### - Bash
```
$ ./combiner
```
### - Windows 
```
$ combiner.exe 
```
- or double click on the `.exe` file 


You will be prompted to enter the input folder path and the output file path. Make sure the input folder is in the `same directory as the executable`, and don't forget to include the file extension for the output file.

The program will combine all `.txt` files in the input folder into the output file. If the operation is successful, you'll see a message indicating that the files have been combined successfully. Press Enter to exit the program.
