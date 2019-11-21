#define _GNU_SOURCE
#include "shell.h"

int _strlendl(char **str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}
/**
 * _setenv - Add a new enviroment varible. If the variable exist and overwrite
 * if the value not is 0, not do anything if the value is 0. If the variable not
 * exist creat it.
 * newenv: The variable
 * Return: 0 id succes of -1 if fail. (Remember free it)
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	int i, lenenv;
	char *namev, *fvariable, *copystr;

	/*
	 * Declare the name of the new Env Variable inside a malloc with '=' in
	 * the final of string.
	 */
	namev = str_concat(name, "=");
	lenenv = _strlendl(environ);
	fvariable = str_concat(namev, value);
	/*
	 * Search if the newenv have some match inside the Env varibles.
	 */
	for (i = 0; environ[i] != '\0'; i++)
	{
		if ((_strcmp(name, environ[i])) == 0)
		{
			if (overwrite != 0)
			{
				free(environ[i]);
				copystr = _strdup(fvariable);
				environ[i] = copystr;
				free(fvariable);
				free(namev);
				return (0);
			}
		}
	}
	if (environ[i] == '\0')
	{
		newenviron = copyenvdp();
		if (overwrite != 0)
		{
			environ[i] = fvariable;
		}
		environ[i + 1] = '\0';
		environ[i] = replacestr;
		free(nne);
		return (0);
	}
	return (-1);
}
