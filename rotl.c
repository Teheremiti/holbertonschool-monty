#include "monty.h"

/**
 * rotl - function that rotates the stack to the top.
 * @top: head of structure
 * @line: number of line
 */

void rotl(stack_t **top, unsigned int line)
{
	stack_t *tmp = *top, *input;
	(void)line;

	if (*top == NULL || (*top)->next == NULL)
		return;
	input = (*top)->next;
	input->prev = NULL;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *top;
	(*top)->next = NULL;
	(*top)->prev = tmp;
	*top = input;
}
