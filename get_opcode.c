#include "monty.h"

/**
 * opcode - Get the function associated to an opcode and execute it
 *
 * @top: Top of the stack
 * @arg: Current argument in the bytecode file
 * @line: Current line in the stack
 *
 * Return: (void)
 */

void opcode(stack_t **top, char *arg, unsigned int line)
{
	int i;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	for (i = 0; op[i].opcode; i++)
	{
		if (strcmp(op[i].opcode, arg) == 0)
		{
			op[i].f(top, line);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line, arg);
	free_stack(*top);
	exit(EXIT_FAILURE);
}
