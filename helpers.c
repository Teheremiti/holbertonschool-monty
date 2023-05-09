#include "monty.h"

/**
 * free_stack - Free a stack structure
 *
 * @top: Top of the stack
 *
 * Return: (void)
 */

void free_stack(stack_t *top)
{
	stack_t *tmp;

	while (top)
	{
		tmp = top;

		free(top->next);
		free(top->prev);

		top = tmp->prev;
	}

	free(top);
}
