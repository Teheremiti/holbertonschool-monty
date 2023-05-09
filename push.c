#include "monty.h"

global_t global = {NULL};

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
	char *num;
	stack_t *new = NULL;

	if (global.arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		global.status = EXIT_FAILURE;
		return;
	}

	num = global.arg;
	if (*num == '-')
		num++;

	if (!is_num(num))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		global.status = EXIT_FAILURE;
		return;
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		global.status = EXIT_FAILURE;
		return;
	}

	new->n = atoi(num);
	new->next = *top;
	new->prev = NULL;

	if (*top)
		(*top)->prev = new;

	*top = new;
}
