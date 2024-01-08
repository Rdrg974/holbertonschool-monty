# <p align="center">C - The Monty Program </p>

## Table of Contents

-   [Objective](#Objective)
-   [Description](#Descritpion)
-   [Requirements](#Requirements)
-   [Compilation command](#Compilation-command)
-   [Mandatory Tasks](#Mandatory-tasks)
-   [Flowchart](#Flowchart)
-   [Installation](#Installation)
-   [Thanks](#Thanks)
-   [Authors](#Authors)

## Objective

The goal of this project is to create an interpreter for Monty ByteCodes files

## Description

The program will read file given in input by the user and execute the command found on each lines, provided there are correct.
It will print an error message if the command are invalid, or if an error occur during command execution. 

## Requirements

-   Allowed editors: `vi`, `vim`, `emacs`
-   All files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic
-   All your files should end with a new line
-   A `README.md` file, at the root of the folder of the project is mandatory
-   Code must follow the `Betty` style
-   Allowed to use a maximum of one global variable
-   No more than 5 functions per file
-   The prototypes of all functions should be included in header file called `monty.h`
-   Header file should be pushed
-   All header files should be include guarded
-   Tasks are expected to be done in the order shown in the project

## Compilation command

gcc -Wall -Werror -Wextra -pedantic *.c -o monty

## Mandatory Tasks

### Task 0. push, pall

- Implement the `push` and pall opcodes.

**The `push` opcode**

- The opcode `push` pushes an element to the stack.

  * Usage: `push <int>`
    * where `<int>` is an integer
  * if `<int>` is not an integer or if there is no argument given to `push`, print the error message `L<line_number>: usage: push integer`, followed by a new line, and exit with the status EXIT_FAILURE
  * where `line_number` is the line number in the file
  * You won’t have to deal with overflows. Use the `atoi` function

**The pall opcode**

- The opcode `pall` prints all the values on the stack, starting from the top of the stack.

  * Usage `pall`
  * Format: see example
  * If the stack is empty, don’t print anything

```
julien@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1
julien@ubuntu:~/monty$

```

### Task 1. pint

- Implement the `pint` opcode.

**The pint opcode**

- The opcode `pint` prints the value at the top of the stack, followed by a new line.

  * Usage: `pint`
  * If the stack is empty, print the error message `L<line_number>: can't pint, stack empty`, followed by a new line, and exit with the status `EXIT_FAILURE`

```
julien@ubuntu:~/monty$ cat bytecodes/06.m 
push 1
pint
push 2
pint
push 3
pint
julien@ubuntu:~/monty$ ./monty bytecodes/06.m 
1
2
3
julien@ubuntu:~/monty$ 
```

### Task 2. pop

- Implement the `pop` opcode.

*The pop opcode*

- The opcode `pop` removes the top element of the stack.

  * Usage: `pop`
  * If the stack is empty, print the error message `L<line_number>: can't pop an empty stack`, followed by a new line, and exit with the status `EXIT_FAILURE`

```
julien@ubuntu:~/monty$ cat bytecodes/07.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
julien@ubuntu:~/monty$ ./monty bytecodes/07.m 
3
2
1
2
1
1
julien@ubuntu:~/monty$ 
```

### Task 3. swap

- Implement the `swap` opcode.

**The swap opcode**

The opcode `swap` swaps the top two elements of the stack.

  * Usage: `swap`
  * If the stack contains less than two elements, print the error message `L<line_number>: can't swap, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`

```
julien@ubuntu:~/monty$ cat bytecodes/09.m 
push 1
push 2
push 3
pall
swap
pall
julien@ubuntu:~/monty$ ./monty bytecodes/09.m 
3
2
1
2
3
1
julien@ubuntu:~/monty$ 
```

### Task 4. add

- Implement the `add` opcode.

**The add opcode**

- The opcode `add` adds the top two elements of the stack.

  * Usage: `add`
  * If the stack contains less than two elements, print the error message L<line_number>: can't add, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
  * The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
      * The top element of the stack contains the result
      * The stack is one element shorter

```
julien@ubuntu:~/monty$ cat bytecodes/12.m 
push 1
push 2
push 3
pall
add
pall

julien@ubuntu:~/monty$ ./monty bytecodes/12.m 
3
2
1
5
1
julien@ubuntu:~/monty$
```

### Task 5. nop

- Implement the `nop` opcode.

**The nop opcode**

The opcode `nop`` doesn’t do anything.

  * Usage: `nop`

## Installation

### Install and run:

To install and run monty, follow these steps:

Clone the repository using the following command:
`
git clone https://github.com/Rdrg974/holbertonschool-monty.git
`

Navigate to the directory where the repository was cloned.

Compile the program by running the following command:
`
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
`

Run the program by typing the following command:
`
./monty <bytecodes file_name>
`

### Using the monty program 

To use our monty, you need a monty file.

The program will read the file line by line and execute the command and print the output on the screen.

## Thanks

Many warm thanks to all the Holberton School peers who helped and brought joy throughout the many challenges of this project.

## Authors

   Abdou Rodrigue Hassany Mohamed <abdou-rodrigue.hassany-mohamed@holbertonstudents.com>  
   Julie Dedieu <julie.dedieu1@gmail.com>
