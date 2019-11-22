#include "shell.h"

/**
 * _setenv - Add a new enviroment varible. If the variable exist and overwrite
 * if the value not is 0, not do anything if the value is 0. If the variable not
 * exist creat it.
 * newenv: The variable
 * Return: 0 id succes of -1 if fail. (Remember free it)
 */
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
char ** _setenv(char **environ, const char *name, const char *value)
{
	int i, lenenv;
	char *namev, *fvariable, *copy_new_env, **newenviron;

	/*
	 * Declare the name of the new Env Variable inside a malloc with '=' in
	 * the final of string.
	 */
	namev = str_concat((char *)name, "=");
	lenenv = _strlendl(environ);
	fvariable = str_concat(namev, (char *)value);
	/*
	 * Search if the newenv have some match inside the Env varibles.
	 */
	for (i = 0; environ[i] != '\0'; i++)
	{
		if ((_strcmp((char *)name, environ[i])) == 0)
		{
			if (value != NULL)
			{
				free(environ[i]);
				copy_new_env = _strdup(fvariable);
				environ[i] = copy_new_env;
				free(fvariable);
				free(namev);
				return (environ);
			}
		}
	}
	if (environ[i] == '\0')
	{
		newenviron = _copyenvdp(environ, lenenv, lenenv + 1);
		if (newenviron == 0)
		{
			free(fvariable);
			perror("Could not make the copy");
			return (NULL);
		}
		copy_new_env = _strdup(fvariable);
		newenviron[lenenv] = copy_new_env;
		environ = newenviron;
		free(fvariable);
		if (copy_new_env == 0)
		{
			perror("Not allocate memory in the replica");
			return (NULL);
		}
		return (environ);
	}
	return (NULL);
}
