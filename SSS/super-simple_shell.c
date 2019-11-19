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
void handle()
{
	write(STDOUT_FILENO, "\n#cisfun$ ", 10);
	return;
}

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "/home/vagrant/simple_shell/SSS", NULL};
	int status;
	pid_t child;
	char *buffer = NULL;
	char *ptr;

	while (1)
	{
		int lenbuf = 0;
		size_t len = 0;

		write(STDOUT_FILENO, "#cisfun$ ", 9);
		signal(SIGINT, handle);
		lenbuf = getline(&buffer, &len, stdin);

		/* Sentencias a getline*/
		if (lenbuf == 0)
			continue;
		if (lenbuf == -1)
		{
			write(STDERR_FILENO, "\n./shell: Can't read the command or find EOF\n", 45);
			free(buffer);
			exit(EXIT_FAILURE);
		}
		else if (lenbuf > 1)
		{
			child = fork();
			ptr = strtok(buffer, "\n");
			if (child == -1)
				perror("Error:");

			/*ejecuciones del proceso hijo*/
			if (child == 0)
			{
				if (execve(ptr, argv, NULL) == -1)
					perror("Error:");
				free(ptr);
				exit(EXIT_SUCCESS);
			}
			else
			{
				free(buffer);
				wait(&status);
			}
		}
		else if (lenbuf == 1)
			free(buffer);
	}
	return (0);
}
