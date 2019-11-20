#define _GNU_SOURCE
#include "shell.h"

/**
 * main -
 *
 * Return:
 */
int main (int argc, char *argv[], char **environ)
{
	if (argc == 2)
	{
		int i = 0;

		for (i = 0; environ[i] != '\0'; i++)
			printf("%s\n", environ[i]);

		printf("\nBefore use _getenv\n");

		_setenv(argv[1]);
		for (i = 0; environ[i] != '\0'; i++)
			printf("%s\n", environ[i]);

		printf("\nAfter use _setenv\n");
		return (0);
	}
	printf("Pls put only 2 parameters\n");
	return (-1);
}
