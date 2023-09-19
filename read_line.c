#include "shell.h"

/**
 * read_line - it read the command from the screen
 * @numChar: number of character read
 * Return: the string of command
 */
char *read_line(int *numChar)
{
	char *input = NULL;
	size_t size = 0;

	*numChar = getline(&input, &size, stdin);
	return (input);
}
