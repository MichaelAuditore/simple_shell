#include "shell.h"
/**
 * shell_loop - initialize the infinite loop for shell
 * to evaluate the input of user, and executes.
 * @argv: Pointer to arguments recieved
 */
void shell_loop(char **argv)
{
	int status = 0;
	pid_t child;
	char *buffer = NULL;
	int len = 0;
	size_t lenb = 0;
	(void)argv;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		signal(SIGINT, _signal);
		len = getline(&buffer, &lenb, stdin);
		if (_strcmp(buffer, "exit\n") == 0 || (int)len == -1)
		{
			if ((int)len == -1)
				write(1, "\n", 1);
			break;
		}
		child = fork();
		if (child == -1)
		{
			free(buffer);
			perror("Error:");
		}
		if (child == 0)
		{
			if (execute(buffer) == -1)
				perror("Error:");
			exit(EXIT_SUCCESS);
		}
		wait(&status);
	}
	free(buffer);
}
