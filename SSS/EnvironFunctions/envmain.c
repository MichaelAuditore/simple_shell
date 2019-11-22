#include "shell.h"

/**
 * main -
 *
 * Return:
 */
int main (int argc, char *argv[], char **environ)
{
	if (argc > 2)
	{
		int i = 0;
		char **newenviron;

		for (i = 0; environ[i] != '\0'; i++)
			printf("%s\n", environ[i]);

		printf("\nBefore use _getenv\n");

		newenviron = _setenv(environ, argv[1], argv[2]);
		environ = newenviron;
		for (i = 0; environ[i] != '\0'; i++)
			printf("%s\n", environ[i]);

		printf("\nAfter use _setenv\n");
		return (0);
	}
	printf("Pls put 2 or more parameters\n");
	return (-1);
}
