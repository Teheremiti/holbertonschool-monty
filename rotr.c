#include "monty.h"

/**
 * rotr - function that rotates the stack to the bottom
 * @top: the head of structure
 * @line: number of line
 */

void rotr(stack_t **top, unsigned int line)
{
	stack_t *tmp = *top;
	(void)line;

	if (*top == NULL || (*top)->next == NULL)
		return;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->prev->next = NULL;
	tmp->next = *top;
	tmp->prev = NULL;
	(*top)->prev = tmp;
	(*top) = tmp;
}
