#include "monty.h"

/**
 * _push - pushes an element to the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 */

void _push(stack_t **doubly, unsigned int cline)
{
	int a, b;

	/*handles error where no file is passed*/
	if (!vglo.arg)
	{
		/*dprintf will output to stderr when fd 2 is passed*/
		dprintf(2, "L%u: ", cline);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	/*handles error where <int> is not an interger*/
	for (b = 0; vglo.arg[b] != '\0'; b++)
	{
		if (!isdigit(vglo.arg[b]) && vglo.arg[b] != '-')
		{
			dprintf(2, "L%u: ", cline);
			dprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	/*use atoi to avoid dealing with overflows*/
	a = atoi(vglo.arg);

	/*if vglo.lifo is 1, is queue, else is stack*/
	if (vglo.lifo == 1)
		add_dnodeint(doubly, a);
	else
		add_dnodeint_end(doubly, a);
}

/**
 * _pall - prints ALL values on the stack, starting from the top of the stack
 *
 * @doubly: head of the linked list
 * @cline: line numbers
 */

void _pall(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	/*cline goes unused in this case*/
	(void)cline;

	aux = *doubly;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * _pint - prints SPECIFICALLY the value at the top of the stack,
 * followed by a newline
 *
 * @doubly: head of the linked list
 * @cline: line number
 */

void _pint(stack_t **doubly, unsigned int cline)
{
	/*cline is once again unused, keep it for consistency's sake*/
	(void)cline;

	if (*doubly == NULL)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "can't pint, stack empty\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	/*prints value in head of linked list*/
	printf("%d\n", (*doubly)->n);
}

/**
 * _pop - removes SPECIFICALLY the top element of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 */

void _pop(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;

	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = *doubly;
	*doubly = (*doubly)->next;
	free(aux);
}

/**
 * _swap - swaps SPECIFICALLY the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 */

void _swap(stack_t **doubly, unsigned int cline)
{
	int swp = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, swp++)
		;

	if (swp < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	/*this is where the swap occurs*/
	aux = *doubly;
	*doubly = (*doubly)->next;
	aux->next = (*doubly)->next;
	aux->prev = *doubly;
	(*doubly)->next = aux;
	(*doubly)->prev = NULL;
}
