#include "monty.h"

/**
 * push_node - Insert an element by following the 'stack' method
 *
 * @top: Top of the stack
 * @num: Integer to insert
 *
 * Return: (void)
 */

void push_node(stack_t **top, char *num)
{
	stack_t *new =  malloc(sizeof(stack_t));

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


/**
 * enqueue - Insert an element by following the 'queue' method
 *
 * @top: Front of the queue
 * @num: Integer to insert
 *
 * Return: (void)
 */

void enqueue(stack_t **top, char *num)
{
	stack_t *tmp = *top;
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		global.status = EXIT_FAILURE;
		return;
	}

	new->n = atoi(num);
	new->next = NULL;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			new->prev = tmp;
			tmp->next = new;
			return;
		}
		tmp = tmp->next;
	}

	new->prev = NULL;
	*top = new;
}


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
	char *num = NULL;

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

	global.format ? enqueue(top, num) : push_node(top, num);
}
