#include "monty.h"
#include <ctype.h>

/**
 * pchar - prints the char at the top of the stack.
 * @top: the head of structure
 * @line: number of line
 */

void pchar(stack_t **top, unsigned int line)
{
	int isNotLetter;

	if (!*top)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		global.status = EXIT_FAILURE;
		return;
	}

	isNotLetter = ((*top)->n < 'A' || (*top)->n > 'Z') &&
		 ((*top)->n < 'a' || (*top)->n > 'z');
	if (isNotLetter)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		global.status = EXIT_FAILURE;
		return;
	}
	printf("%c\n", (char)(*top)->n);
}
