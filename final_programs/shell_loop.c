#define _GNU_SOUCE
#include "shell.h"

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
char **_create_dpstr(char *ptr)
{
	char *token, *save;
	char **dpstr;
	int i = 0;

	if (ptr[0] == '/')
	{
		save = strtok(ptr, "/")
		while (save != NULL)
			/*para hacer esto queda util usar la funcion strrchr*/
			save = strtok(NULL, "/");
	}
	dpstr = malloc(sizeof(char *) * 4);
	save = strtok(ptr, " ");
	token = save;
	while (token != NULL)
	{
		dpstr[i] = token;
		token = strtok(NULL, " \0");
		i++;
	}
	dpstr[i] = NULL;

	if (i == 1)
	{
		/*solo paso el comando a ejecutar, es decir que no trae flags y
		  debe hacerse en el directorio actual*/
		dpstr[i] = ".";
		dpstr[i + 1] = NULL;
		return (dpstr);
	}
	if (i == 2)
	{
		/*aqui existe la posibilidad que pasen o una flag o el directorio
		  que se desea poner como comando*/
		if (dpstr[i - 1][0] == '-')
		{
			/*se pasp una flag asi que se debe concatenar con .*/
			dpstr[i] = ".";
			dpstr[i + 1] = NULL;
			return (dpstr);
		}
		else if (dpstr[i - 1][0] == '/')
		{
			/*se paso un directorio. no se concatena. Parte con miguel*/
			return (dpstr);
		}
	}
	if (i == 3)
	{
		if (dpstr[2][0] != '-')
		{
			perror("porfavor ponga una flag como parametro");
			return (NULL);
		}
		return (dpstr);
	}
	perror("Los parametros dados exegeden el limite necesario");
	return (NULL);
}
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
	/* char *argv[] = {"/bin/ls", "/home/vagrant/simple_shell/SSS", NULL}; */
	int status;
	pid_t child;
	char *buffer = NULL;
	char *ptr, *command, *co_directory, *directory, *copypath,**secondarg;
	struct stat st;

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
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		else if (lenbuf > 1)
		{
			child = fork();
			if (child == -1)
				perror("Error:");

			ptr = strtok(buffer, "\n");
			if (ptr[0] == '/')
			{
				if (child == 0)
				{
					copypath = _getenv("PATH");
					if (copypath == NULL)
						perror("Not found PATH Variable"), exit(EXIT_FAILURE);

					command = _strdup(copypath);
					free(copypath);

					secondarg = _create_dpstr(ptr);
					co_directory = strtok(NULL, " ");
						if (stat(co_directory, &st) == 0)
						{
							if (execve(co_directory, secondarg, NULL) == -1)
								perror("Error:");
							free(ptr);
							free(command);
							freedp(secondarg);
							exit(EXIT_SUCCESS);
						}
						else
							directory = strtok(NULL, ":\0");
					free(command);
					free(ptr);
					free(secondarg);
					exit(0);
				}
				else
				{
					free(buffer);
					wait(&status);
				}
			}
			else
			{
				ptr = str_concat("/", ptr);
				if (child == 0)
				{
					copypath = _getenv("PATH");
					if (copypath == NULL)
						perror("Not found PATH Variable"), exit(EXIT_FAILURE);

					command = _strdup(copypath);
					free(copypath);

					secondarg = _create_dpstr(ptr);
					ptr = strtok(ptr, " ");
					directory = strtok(command, "=");
					directory = strtok(NULL, ":");
					while (directory != NULL)
					{
						co_directory = str_concat(directory, ptr);
						if (stat(co_directory, &st) == 0)
						{
							if (execve(co_directory, secondarg, NULL) == -1)
								perror("Error:");
							free(ptr);
							free(command);
							freedp(secondarg);
							exit(EXIT_SUCCESS);
						}
						else
							directory = strtok(NULL, ":\0");
					}
					free(command);
					free(ptr);
					free(secondarg);
					exit(0);
				}
				else
				{
					free(buffer);
					wait(&status);
				}
			}
		}
		else if (lenbuf == 1)
			free(buffer);
	}
	return (0);
}
