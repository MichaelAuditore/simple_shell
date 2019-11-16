#define _GNU_SOURCE
#include "shell.h"

void handle_ctrlC(int sig)
{
	write(1, "\n$ ", 3);
}

int main(void)
{
	char *buffer = NULL;
	int lenbuf = 0;
	size_t len = 0;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		lenbuf = getline(&buffer, &len, stdin);
		signal(SIGINT, handle_ctrlC);
		if (lenbuf == 0)
			continue;
		else if (lenbuf == -1)
		{
			write(STDERR_FILENO, "Can't read the command or find EOF\n", 35);
			exit(EXIT_FAILURE);
		}
		else if (lenbuf > 0)
			write(STDOUT_FILENO, buffer, lenbuf);
	}
	return (0);
}
