#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack,
 * @top: the head of structure
 * @line: number of line
 */

void pstr(stack_t **top, unsigned int line)
{
	(void)line;
	stack_t *tmp = *top;

	while (tmp)
	{
		if (tmp->n <= 0 || tmp->n > 127)
		{
			break;
		}
		putchar((char) tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}