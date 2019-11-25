#include "shell.h"
/**
 * _setenv - change the value of a variable if exist or create it isn't exist
 * @name: name of variable to change the value
 * @value: Value of variable
 * @overwrite: If value in nonzero change the value of a variable
 * Return: 0 is success or 1 is error
 */
int _setenv(char *name, char *value, int overwrite)
{
	char *new_var;
	int flag, i = 0;

	new_var = malloc(_strlen(name) + _strlen(value) + 2);
	if (new_var == NULL)
		return (-1);
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
	if (flag == 1)
	{
		_strcpy(new_var, name);
		_strcat(new_var, "=");
		_strcat(new_var, value);
		environ[i] = malloc((_strlen(new_var)) + 1);
		_strcpy(environ[i], new_var);
		environ[i + 1] = NULL;
	}
	if (flag == 0 && overwrite != 0)
	{
		_strcpy(new_var, name);
		_strcat(new_var, "=");
		_strcat(new_var, value);
		environ[i] = malloc((_strlen(new_var)) + 1);
		_strcpy(environ[i], new_var);
	}
	free(new_var);
	return (0);
}
