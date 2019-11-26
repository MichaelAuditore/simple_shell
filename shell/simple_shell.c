#include "shell.h"
/**
 * itoa - converts a number into string
 * @nerrors: Number to cast
 * Return: new pointer with number converted to string
 */
char *itoa(size_t nerrors)
{
	char base[] = "0123456789";
	char *newstr;
	unsigned int len = 0;
	int number = nerrors;

	for (len = 0; nerrors > 0; len++)
	{
		nerrors = nerrors / 10;
	}

	newstr = malloc(sizeof(char) * len + 1);
	if (newstr == NULL)
		return (NULL);
	do {
		newstr[--len] = base[number % 10];
		number /= 10;
	} while (number != 0);
	newstr[len + 1] = '\0';
	return (newstr);
}
/**
 * write_error - write an error when no founds a file or directory
 * @name: name of executable
 * @buffer: address of command searched to execute and no found
 * @nerrors: Number of the error
 */
void write_error(char *name, char **buffer, size_t nerrors)
{
	char *n = itoa(nerrors);
	write(2, name, _strlen(name));
	write(2, ": ", 2);
	write(2, n, _strlen(n));
	write(2, ": ", 2);
	write(2, *buffer, _strlen(*buffer));
	write(2, ": not found\n", 12);
	free(n);
}
/**
 * shell_loop - initialize the infinite loop for shell
 * to evaluate the input of user, and executes.
 * @argv: Pointer to arguments recieved
 */
void shell_loop(char **argv)
{
	int errors = 0;
	int status = 0;
	pid_t child;
	char *buffer = NULL;
	int len = 0;
	size_t lenb = 0;

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
			{
				errors++, write_error(argv[0], &buffer, errors);
				_exit(child);
			}
			exit(EXIT_SUCCESS);
		}
		wait(&status);
	}
	free(buffer);
}
