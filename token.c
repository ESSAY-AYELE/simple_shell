#include "shell.h"

/**
 * tokenize - tokenizes the input string
 * @input: input string.
 * Return: string splitted.
 */
char **tokenize(char *input)
{
	size_t bsize;
	size_t i;
	char **tokens;
	char *token;
	char *tok_delim = " \n\t\r";

	bsize = 1024;
	tokens = malloc(sizeof(char *) * (bsize));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	token = _strtok(input, tok_delim);
	tokens[0] = token;

	for (i = 1; token != NULL; i++)
	{
		if (i == bsize)
		{
			bsize += 1024;
			tokens = _reallocdp(tokens, i, sizeof(char *) * bsize);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = _strtok(NULL, tok_delim);
		tokens[i] = token;
	}

	return (tokens);
}
