#include "monty.h"

/**
 * pint - Print the value at the top of the stack
 *
 * @top: Top of the stack
 * @line: Current line in the stack
 *
 * Return: (void)
 */

void pint(stack_t **top, unsigned int line)
{
	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*top)->n);
}
