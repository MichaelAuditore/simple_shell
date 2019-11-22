#include "shell.h"

/**
 * _setenv - Add a new enviroment varible. If the variable exist and overwrite
 * if the value not is 0, not do anything if the value is 0. If the variable not
 * exist creat it.
 * newenv: The variable
 * Return: 0 id succes of -1 if fail. (Remember free it)
 */
void freedp(char **str)
{
	int i, j = 0;

	while (str[j] != '\0')
		j++;

	for (i = 0; i < j; i++)
		free(str[i]);
	free(str);
	return;
}
