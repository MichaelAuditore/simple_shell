#include "shell.h"
/**
 * main - start the shell
 * @argc: Counter of arguments received
 * @argv: Pointer to arguments received
 * @envp: Pointer to environment variables
 * Return: Always 0
 */
int main(int argc, char **argv, char *envp[])
{
	(void)argc;
	shell_loop(argv, envp);
	return (0);
}
