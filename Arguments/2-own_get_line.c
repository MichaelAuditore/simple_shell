#define _GNU_SOURCE
#include "shell.h"

void handle_ctrlC(int sig)
{
	write(1, "\n$ ", 3);
}

ssize_t _getline(char **buffer)
{
	static int len;

	*buffer = (char *)malloc(1024);
	signal(SIGINT, handle_ctrlC);
	write(STDOUT_FILENO, "$ ", 2);
     while((len = read(STDIN_FILENO, *buffer, 1024)) == 0 && len != EOF);
	return (len);
}
