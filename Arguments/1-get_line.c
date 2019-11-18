#define _GNU_SOURCE
#include "shell.h"

void handle_ctrlC(int sig)
{
	write(1, "\n$ ", 3);
}

int main(void)
{
	while (1)
	{
		char *buffer = NULL;
		int lenbuf = 0;
		size_t len = 0;

		/* signal(SIGINT, handle_ctrlC); */
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		lenbuf = getline(&buffer, &len, stdin);
		if (lenbuf == 0)
			continue;
		else if (lenbuf == -1)
		{
			write(STDERR_FILENO, "\n./shell: Can't read the command or find EOF\n", 45);
			free(buffer);
			exit(EXIT_FAILURE);
		}
		else if (lenbuf > 0)
		{
			write(STDERR_FILENO, "./shell: No such file or directory\n", 35);
			free(buffer);
		}
	}
	return (0);
}
