#define _GNU_SOURCE
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
 * getenv - get a value of a variable
 *
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
/**
 * main - start to find a variable
 * Return: 0
 */
int main(int argc, char **argv)
{
	const char *name = "USER";
	char *value;

	value = _getenv(argv[1]);

	printf("Value of environment variable %s: %s\n", argv[1], value);
	return (0);
}
