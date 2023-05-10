#include "monty.h"

/**
 * mul - Multiply the two top elements of the stack
 *
 * @top: Top of the stack
 * @line: Current line in the bytecode file
 *
 * Return: (void)
 */

void mul(stack_t **top, unsigned int line)
{
	stack_t *next = NULL, *tmp = NULL;

	if (*top)
	{
		if ((*top)->next)
		{
			next = (*top)->next;
			next->n *= (*top)->n;

			tmp = *top;
			*top = tmp->next;
			free(tmp);
			return;
		}
	}

	fprintf(stderr, "L%d: can't mul, stack too short\n", line);
	global.status = EXIT_FAILURE;
}
