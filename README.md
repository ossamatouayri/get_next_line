# Get Next Line
## About
The Get Next Line project is designed to implement a function that reads and returns one line at a time from a file descriptor in C. This task offers valuable insights into file handling, buffering, and efficient memory management, providing foundational skills for working with files and persistent data in programming.

## How It Works
##### The goal is to build a function that:

Reads input from a file or standard input.
Returns one line at a time, including proper handling of EOF and dynamic buffers.
For detailed specifications, please refer to the project subject.

## Usage
### Requirements
##### To use this function, ensure you have:

 ###### A GCC compiler.
 ###### Standard C libraries.
 
### Compilation
Include the header file in your project:

```bash
#include "get_next_line.h"
```
Compile the files with the buffer size defined during compilation:

```bash
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=<size> get_next_line.c get_next_line_utils.c
```
## Testing
##### To test the function:

###### 1. Edit get_next_line.c to include a main function for testing.
###### 2. Modify or create test files like test.txt to check different input scenarios.
###### 3. Compile and execute the program with your desired buffer size:
```bash
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=<xx> get_next_line.c get_next_line_utils.c && ./a.out
```
Test the function with various buffer sizes to ensure its reliability and performance.
