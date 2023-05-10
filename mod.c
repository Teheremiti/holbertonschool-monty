#include "monty.h"

/**
 * mod - Compute the rest of the division of the second top element of
 * the stack by the top element of the stack
 *
 * @top: Top of the stack
 * @line: Current line in the bytecode file
 *
 * Return: (void)
 */

void mod(stack_t **top, unsigned int line)
{
	stack_t *next = NULL, *tmp = NULL;

	if (*top)
	{
		if ((*top)->next)
		{
			if ((*top)->n == 0)
			{
				fprintf(stderr, "L%d: division by zero\n", line);
				global.status = EXIT_FAILURE;
				return;
			}

			next = (*top)->next;
			next->n %= (*top)->n;

			tmp = *top;
			*top = tmp->next;
			free(tmp);
			return;
		}
	}

	fprintf(stderr, "L%d: can't mod, stack too short\n", line);
	global.status = EXIT_FAILURE;
}
