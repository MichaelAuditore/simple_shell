#define _GNU_SOURCE
#include "shell.h"
/**
 * _getenv - get a enviroment variable
 * @name: Constant with the name of environment variable to search
 * Return: the variable
 */
char *_getenv(const char *name)
{
	if (name)
	{
		int i = 0;
		char *tmp, *ptr;

			while (environ[i] != NULL)
			{
				if (_strcmp((char *)name, environ[i]) == 0)
				{
					return (environ[i]);
				}
				else
					return (NULL);
				i++;
			}
	}
	return (NULL);
}
