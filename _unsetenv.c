#include "shell.h"
/**
 * _unsetenv - deletes a variable
 * @name: Name of variable to delete
 * Return: 0
 */
int _unsetenv(char *name)
{
	int flag, i = 0;

	while (environ[i] != NULL)
	{
		if ((_strcmp(name, environ[i])) == 0)
		{
			flag = 0;
			break;
		}
		else
			flag = 1;
		i++;
	}
	if (flag == 0)
		while (environ[i] != NULL)
		{
			if (environ[i + 1] != NULL)
				_strcpy(environ[i], environ[i + 1]);
			else
				environ[i] = NULL;
			i++;
		}
	free(environ[i]);
	return (0);
}
