#include "shell.h"
/**
 * _strcmp - compare a string adding all characters
 * @s1: String one
 * @s2: String two
 * Return: A hash
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int res = 0;

	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			res = (s1[i] - s2[i]);
			break;
		}
		i++;
	}
	return (res);
}
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
