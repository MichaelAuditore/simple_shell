#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "/home/vagrant/simple_shell/SSS", NULL};
	int status;
	size_t i = 0;
	pid_t child;
	char *buffer = NULL;
	char *ptr;

	while (1)
	{
		printf("#cisfun$ ");
		getline(&buffer, &i, stdin);
		ptr = strtok(buffer, "\n");
		if (ptr == NULL)
		child = fork();
		if (child == -1)
		{
			perror("Error:");
			free(ptr);
		}
		if (child == 0)
		{
			if (execve(ptr, argv, NULL) == -1)
			{
				perror("Error:");
			}
			free(ptr);
		}
		else
		{
			free(buffer);
			wait(&status);
		}
	}
	return (0);
}
