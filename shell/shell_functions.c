#include "shell.h"
/**
 * _signal - block signal of Ctrl + C
 * @s: signal to verify
 * Return: Always 0.
 */
void _signal(int s)
{
	(void)s;
	write(STDOUT_FILENO, "\n#cisfun$ ", 10);
}
/**
 * execute - evaluate the input and execute the program
 * depending arguments
 * @input: Pointer to pointer arguments
 * Return: 0 is success or -1 is error
 */
int execute(char **input)
{
	int i = 0, j = 0, k = 0;
	char *path = *input;
	char *exec;
	char *tmpexe = _strdup(*input);
	char **argv = NULL;

	path = strtok(path, " \n\t");
	exec = path;
	while (path != NULL)
	{
		i++;
		path = strtok(NULL, " \n\t");
	}
	argv = malloc(i + 1);
	tmpexe = strtok(tmpexe, " \n\t");
	for (j = 0; tmpexe != NULL; j++)
	{
		argv[j] = _strdup(tmpexe);
		tmpexe = strtok(NULL, " \n\t");
	}
	argv[j] = NULL;
	execve(exec, argv, NULL);
	while (argv[k] != NULL)
	{
		free(argv[k]);
		k++;
	}
	free(argv);
	free(tmpexe);
	return (0);
}
/**
 * print_env - print the environment variables
 * @envp: Pointer to environment variables
 */
void print_env(char *envp[])
{
	int i = 0;

	while (envp[i] != NULL)
	{
		dprintf(1, "%s\n", envp[i]);
		i++;
	}
}
