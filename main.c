#include "shell.h"
/**
 * signal_handler - handles a signal
 * @sig: the signal
 */
void signal_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\nthe signal", 11);
}

/**
 * main - Entry point
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success.
 */
int main(void)
{
	signal(SIGINT, signal_handler);
	loop();
	return (0);
}
