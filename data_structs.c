#include "monty.h"

/**
 * stack - Set the format of the data to 'stack'
 *
 * @top: Top of the stack
 * @line: Current line in the bytecode file
 *
 * Return: (void)
 */

void stack(stack_t **top, unsigned int line)
{
	(void) top;
	(void) line;

	global.format = 0;
}


/**
 * queue - Set the format of the data to 'stack'
 *
 * @top: Top of the stack
 * @line: Current line in the bytecode file
 *
 * Return: (void)
 */

void queue(stack_t **top, unsigned int line)
{
	(void) top;
	(void) line;

	global.format = 1;
}
