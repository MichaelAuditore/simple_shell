#include "shell.h"
/**
 * _getenv - get a value of a variable
 * @name: Constant with the name of environment variable to search
 * Return: the variable
 */
char *_getenv(const char *name)
{
	int i = 0;
	char *tmp, *ptr;

	while (environ[i] != NULL)
	{
		if (_strcmp((char *)name, environ[i]) == 0)
		{
			tmp = environ[i];
			ptr = strtok(tmp, "=");
			ptr = strtok(NULL, "\0");
			break;
		}
		i++;
	}
	return (ptr);
}
