#include "monty.h"

/**
 * push - Insert an element into the stack
 *
 * @top: Top of the stack
 * @line: Current line count in the bytecode file
 *
 * Return: (void)
 */

void push(stack_t **top, unsigned int line)
{
	char *num = global.arg;
	stack_t *new = NULL;

	if (*num == '-')
		num++;

	if (num == NULL || is_num(num))
	{
		free_stack(*top);
		fprintf(stderr, "L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free_stack(*top);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(num);
	new->next = *top;
	new->prev = NULL;

	if (*top)
		(*top)->prev = new;

	*top = new;
}
