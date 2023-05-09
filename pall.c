#include "monty.h"

/**
 * pall - Print all the values in the stack
 *
 * @top: Top of the stack
 * @line: Current line count in the stack
 *
 * Return: (void)
 */

void pall(stack_t **top, unsigned int line)
{
	(void) line;
	stack_t *tmp = *top;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
