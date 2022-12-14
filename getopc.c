#include "monty.h"

/**
 * getopc - grabs the right opcode
 *
 * @opc: opcode given
 *
 * Return: pointer to the function that executes the opcode
 */

void (*getopc(char *opc))(stack_t **stack, unsigned int line_number)
{
	/* double array that holds the opcode string to compare to, plus*/
	/* the function used to execute the opcode*/
	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};
	size_t loop;

	/* for loop that compares given opc to the array to determine which*/
	/* elements of the array to grab and return*/
	for (loop = 0; instruct[loop].opcode; loop++)
	{
		if (strcmp(instruct[loop].opcode, opc) == 0)
			break;
	}

	return (instruct[loop].f);
}
