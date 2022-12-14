#include "monty.h"

/*our singular allowed global variable*/
global_t vglo;

/**
 * free_vglo - frees variables inside vglo
 */

void free_vglo(void)
{
	free_dlistint(vglo.head);
	free(vglo.buffer);
	fclose(vglo.fd);
}

/**
 * start_vglo - declares the variables inside global_t struct
 *
 * @fd: file descriptor passed by main
 */

void start_vglo(FILE *fd)
{
	vglo.lifo = 1;
	vglo.cont = 1;
	vglo.arg = NULL;
	vglo.head = NULL;
	vglo.fd = fd;
	vglo.buffer = NULL;
}

/**
 * check_input - checks given input and determines if it exists
 *
 * @ac: argument count
 * @ar: array of arguments passed
 *
 * Return: file struct
 */

FILE *check_input(int ac, char **ar)
{
	FILE *fd;

	/*Checks to see if file was given, and if more than one argument*/
	if (ac == 1 || ac > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/*primes fd with file given with reading permissions*/
	fd = fopen(ar[1], "r");

	/*checks to see if file is openable*/
	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", ar[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - monty code interpreter!
 *
 * @ac: argument count
 * @ar: array of arguments passed
 *
 * Return: Always 0 to determine success
 */

int main(int ac, char **ar)
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 999;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	/* reads given file and imprints it to fd*/
	fd = check_input(ac, ar);
	/*initializes global variables with .fd as fd*/
	start_vglo(fd);
	/*stores the return value of getline in a ssize_t var*/
	nlines = getline(&vglo.buffer, &size, fd);

	while (nlines != -1)
	{
		/*tokenizes first argument from getline and stores it*/
		lines[0] = _strtok(vglo.buffer, " \t\n");

		if (lines[0] && lines[0][0] != '#')
		{
			/*retrieves the function given by lines array*/
			f = getopc(lines[0]);
			/*handles error where function does not exist*/
			if (!f)
			{
				dprintf(2, "L%u: ", vglo.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_vglo();
				exit(EXIT_FAILURE);
			}
			/*further tokenizes buffer and stores it in arg*/
			vglo.arg = _strtok(NULL, " \t\n");
			/*executes function with head and cont given*/
			f(&vglo.head, vglo.cont);
		}
		nlines = getline(&vglo.buffer, &size, fd);
		vglo.cont++;
	}
	free_vglo();
	return (0);
}
