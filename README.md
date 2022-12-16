# C - Holberton Monty
[![holberton](https://user-images.githubusercontent.com/113919186/207066528-0e8569ab-4132-4b02-8eb3-176e58a0dc7b.png)](https://www.holbertonschool.com/)
## Description
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.
### Requirements

If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE

If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE
where <file> is the name of the file

If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
where is the line number where the instruction appears.

Line numbers always start at 1
The monty program runs the bytecodes line by line and stop if either:
it executed properly every line of the file
it finds an error in the file
an error occured

If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.

You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)
## Usage
Usage:  uses a monty file
where file is the path to the file containing Monty byte code
## File Description
+ **opcodes1.c** - contains functions:
    + *_push* - pushes an element to the stack
    + *_pall* - prints ALL values on the stack, starting from the top of the stack
    + *_pint* - prints SPECIFICALLY the value at the top of the stack, followed by a newline
    + *_pop* - removes SPECIFICALLY the top element of the stack
    + *_swap* - swaps SPECIFICALLY the top two elements of the stack
- **opcodes2.c** - contains functions:
    + *_add* - adds SPECIFICALLY the top two elements of the stack
    + *_nop* - literally nothing
    + - **strtok.c** - containts functions:
    + *_ischar* - checks if an element of a string is a char
    + *_strtok* - emulates strtok and saves time
- **monty.h** - contains structures and function inicialization
- **main.c** - contains functions:
- *free_vglo* - frees variables inside vglo
- *start_vglo* - declares the variables inside global_t struct
- *check_input* - checks given input and determines if it exists
- *main* - monty code interpreter
- **getopc.c** - contains functions:
- *getopc* - grabs the right opcode
- **dlistfuncs.c** contains functions:
- *add_dnodeint_end* - add a node at the end of the doubly link list
- *add_dnodeint* - adds a node at the beginning of a doubly link list
- *free_dlistint* - frees the doubly linked list
### Authors
Written by [Jeronimo Lussich](https://github.com/Jerolussich), [Mauricio De Betolaza](https://github.com/Maurlcio)

