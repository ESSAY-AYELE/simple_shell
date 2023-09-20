#include "shell.h"

/**
 * exit_shell - exits the shell
 *
 * @cmd: data relevant (status and args)
 * Return: 0 on success.
 */
int exit_shell(char **cmd)
{
	unsigned int ustatus;
	int is_digit;
	int str_len;
	int big_number;

	if (cmd[1] != NULL)
	{
		ustatus = _atoi(cmd[1]);
		is_digit = _isdigit(cmd[1]);
		str_len = _strlen(cmd[1]);
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			return (1);
		}
	}
	return (0);
}
