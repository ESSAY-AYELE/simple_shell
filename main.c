#include "shell.h"
/**
 *
 */
void signal_handler(int sig)
{
	
int main(int argc, char **argv)
{
	signal(SIGINT, signal_handler);
	loop();
	return (0);
}
