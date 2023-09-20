#include "shell.h"

/**
 * exec_line - finds builtins and commands
 *
 * @cmd: data relevant (args)
 * Return: 1 on success.
 */
int exec_line(char **cmd)
{
	int (*builtin)(char **cmd);

	if (cmd[0] == NULL)
		return (1);

	builtin = get_builtin(cmd[0]);

	if (builtin != NULL)
		return (builtin(cmd));

	return (cmd_exec(cmd));
}

/**
 * _atoi - converts a string to an integer.
 * @s: input string.
 * Return: integer.
 */
int _atoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}
