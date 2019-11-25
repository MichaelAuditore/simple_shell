#include "shell.h"

/**
 * _strrchr - Print after of the last ocurrence
 * @s: My pointer of the string.
 * @c: My ocurrense character.
 * Return: The result of the pointer.
 */
char *_strchr(char *s, char c)
{
	int i, j;

	for (i = 0; *s; i++, s++)
		;
	for (j = 0; j < i; i--, s--)
	{
		if (*s == c)
			break;
	}
	return (*s == c ? s : 0);
}
