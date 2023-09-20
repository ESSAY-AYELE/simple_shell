#include "shell.h"

/**
 * loop - is a shell that execute programe again and again
 */
void loop(void)
{
	char *input = NULL;
	char **arg = NULL;
	int numChar;

	while (1)
	{
		write(STDOUT_FILENO, "=> ", 3);
		input = read_line(&numChar);
		if (input == "q")
			return;
		if (numChar != -1)
		{
			if (input == NULL)
				continue;
			arg = tokenize(input);
			if (!arg)
				perror("ERROR");
			exec_line(arg);
			free(input);
			free(arg);
		}
		else
			free(input);
	}
}
