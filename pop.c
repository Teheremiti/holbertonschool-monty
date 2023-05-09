#include "monty.h"

/**
 * pop - function that removes the top element of the stack.
 * @top: head of stack
 * @i: number of line
 */

void pop(stack_t **top, unsigned int i)
{
	stack_t *tmp;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", i);
		global.status = EXIT_FAILURE;
		return;
	}

	tmp = *top;
	*top = tmp->next;
	free(tmp);
}
