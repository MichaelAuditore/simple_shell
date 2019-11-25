#include "shell.h"
/**
 *
 *
 *
 */
void write_error(char *name, char **buffer)
{
	write(1, name, _strlen(name));
	write(1, ": 1: ", 5);
	write(1, *buffer, _strlen(*buffer));
	write(1, ": not found\n", 12);
}
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
		if (isatty(0) == 1)
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		signal(SIGINT, _signal), len = getline(&buffer, &lenb, stdin);
		if (_strcmp(buffer, "exit\n") == 0 || (int)len == -1)
		{
			if ((int)len == -1 && isatty(0) == 1)
				write(1, "\n", 1);
			break;
		}
		child = fork();
		if (child == -1)
			free(buffer), perror("Error:");
		if (child == 0)
		{
			if (execute(buffer) == -1)
				write_error(argv[0], &buffer);
			exit(EXIT_SUCCESS);
		}
		wait(&status);
	}
	free(buffer);
}
