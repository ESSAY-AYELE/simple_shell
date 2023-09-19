#include "shell.h"

/**
 *
 */
void loop(void)
{	
	char *input = NULL;
	char **arg = NULL;
	int numChar;

	while (1)
	{
		write (STDOUT_FILENO, "=> ", 3);
		input = read_line(&numChar);
		if (input == "q")
			return;
		if (numChar != -1)
		{	
			if (input == NULL)
				continue;
			arg = tokenize(input);
			if (!arg)
				printf("ERROR");
			printf("%s \n%s\n", arg[0], arg[1]);
			//if (arg)
			//	execute(arg);	
		}
	}
}
