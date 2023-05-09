#include "monty.h"

/**
 * swap - function that swaps the top two elements of the stack.
 * @top: the head of structure
 * @i: the number of line
 */

void swap(stack_t **top, unsigned int i)
{
	stack_t *tmp;
	int length = 0;
	int input;

	tmp = *top;

	while (tmp)
	{
		tmp = tmp->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", i);
		free(*top);
		exit(EXIT_FAILURE);
	}
	tmp = *top;
	input = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = input;
}
