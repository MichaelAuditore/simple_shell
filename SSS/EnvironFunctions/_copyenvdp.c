#include "shell.h"

/**
 * _setenv - Add a new enviroment varible. If the variable exist and overwrite
 * if the value not is 0, not do anything if the value is 0. If the variable not
 * exist creat it.
 * newenv: The variable
 * Return: 0 id succes of -1 if fail. (Remember free it)
 */
char **_copyenvdp(char **str, int old_size, int new_size)
{
	char **copy;
	int lendp, i;

	if (old_size > new_size)
	{
		lendp = new_size;
		copy = malloc(sizeof(char *) * (lendp + 1));
	}
	else
	{
		lendp = old_size;
		copy = malloc(sizeof(char *) * (new_size + 1));
	}
	if (copy == 0)
		return (NULL);

	for (i = 0; i < lendp; i++)
		copy[i] = _strdup(str[i]);
	copy[new_size] = '\0';

	return (copy);
}
