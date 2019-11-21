#include "shell.h"

/**
 * _strdup - Copy an string in a new space of memory declarated before for
 * malloc.
 * @str: Ny string of input.
 * Return: The coppy of the string.
 */
char *_strdup(char *str)
{
	char *a;
	int j, k;

	if (str == NULL)
	{
		return (0);
	}
	else
	{
		j = _strlen(str);
		a = (char *)malloc(j * sizeof(char) + 1);
		if (a == NULL)
			return (0);
		for (k = 0; str[k] != '\0'; k++)
		{
			a[k] = str[k];
		}
		return (a);
	}
}
