#define _GNU_SOUCE
#include "shell.h"

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
	char *ptr, *command, *co_directory, *directory;
	struct stat st;

	while (1)
	{
		int lenbuf = 0;
		size_t len = 0;

		write(STDOUT_FILENO, "#cisfun$ ", 9);
		signal(SIGINT, handle);
		lenbuf = getline(&buffer, &len, stdin);
		bufferdp = _convertptdp();
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

			copypath = _getenv("PATH");
			if (copypath == NULL)
				perror("Not found PATH Variable"), exit(EXIT_FAILURE);

			command = _strdup(copypath);
			if (child == 0)
			{
				directory = strtok(command, "=");
				directory = strtok(NULL, ":");
				while (directory != NULL)
				{
					co_directory = str_concat(directory, ptr);
					if (stat(co_directory, &st) == 0)
					{
						if (execve(co_directory, {"ls", "-l", "." NULL}, environ) == -1)
							perror("Error:");
						free(ptr);
						free(command);
						exit(EXIT_SUCCESS);
					}
					else
						directory = strtok(NULL, ":\0");
				}
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
