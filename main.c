#include "monty.h"

/**
 * main - Monty bytecodes files interpreter
 *
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: 0 on SUCCESS, otherwise nothing and exit with status EXIT_FAILURE
 */

int main(int ac, char **av)
{
	FILE *fd;
	char *buffer = NULL, *op = NULL;
	stack_t *top = NULL;
	size_t byteCount;
	unsigned int line = 1;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	global.format = 0;
	while (getline(&buffer, &byteCount, fd) != -1)
	{
		op = strtok(buffer, " $\n");
		global.arg = strtok(NULL, " $\n");

		if (op)
			opcode(&top, op, line);

		if (global.status)
			break;
		line++;
	}
	free(buffer);
	free_stack(top);
	fclose(fd);

	if (global.status)
		exit(global.status);

	return (0);
}
