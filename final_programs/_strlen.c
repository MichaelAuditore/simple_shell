#include "shell.h"

/**
 * _strlen - Copy a string in the final of other string
 * @str: My string.
 * Return: The length of my string.
 */
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}
