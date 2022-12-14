#include "monty.h"

/**
 * _add - adds SPECIFICALLY the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number;
 */

void _add(stack_t **doubly, unsigned int cline)
{
	int ad = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, ad++)
		;

	if (ad < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	/*this is where the sum occurs*/
	aux = (*doubly)->next;
	aux->n += (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * _nop - literally nothing
 *
 * @doubly: useless
 * @cline: useless
 */

void _nop(stack_t **doubly, unsigned int cline)
{
	/*yup*/
	(void)doubly;
	(void)cline;
}
