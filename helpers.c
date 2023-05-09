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
	if (top)
	{
		if (top->next)
			free_stack(top->next);

		free(top);
	}
}


/**
 * is_num - Check if a string is made only of numbers
 *
 * @str: String to check
 *
 * Return: 1 if there is a character other than a digit, otherwise 0
 */

int is_num(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		if (str[i] < '0' || str[i] > '9')
			return (1);

	return (0);
}
