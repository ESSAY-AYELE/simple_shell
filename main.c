#include "shell.h"
/**
 *
 */
void signal_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\nthe signal", 11);
}

/**
 *
 */
int main(int argc, char **argv, char *env[])
{
	signal(SIGINT, signal_handler);
	loop();
	return (0);
}
