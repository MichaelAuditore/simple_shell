#define _GNU_SOURCE
#include "shell.h"

/**
 * _setenv - Add a new enviroment varible. If the variable exist and overwrite
 * if the value not is 0, not do anything if the value is 0. If the variable not
 * exist creat it.
 * newenv: The variable
 * Return: 0 id succes of -1 if fail. (Remember free it)
 */
int _setenv(char *newenv)
{
	if (newenv)
	{
		int i, len_nne/* , j */;
		char *name_new_env, *val_new_env, *replacestr, *nne;
		/* static char *copyenv; */

		/*
		 * Declare the name of the new Env Variable inside a malloc with '=' in
		 * the final of string.
		 */
		name_new_env = strtok(newenv, "=");
		val_new_env = strtok(NULL, "\n");
		len_nne = _strlen(name_new_env);
		len_nne++;
		nne = malloc(len_nne * sizeof(char));
		for (i = 0; name_new_env[i] != '\0'; i++)
			nne[i] = name_new_env[i];
		nne[i] = '=';
/*--------------------------------*/
		/*
		 * Search if the newenv have some match inside the Env varibles.
		 */
		for (i = 0; environ[i] != '\0'; i++)
		{
			if ((_strcmp(name_new_env, environ[i])) == 0)
			{
				/* copyenv = environ[i]; */
				if (val_new_env != NULL)
				{
					replacestr = str_concat(nne, val_new_env);
					/* for (j = 0; replacestr[j] != '\0'; j++) */
					/* 	environ[i][j] = replacestr[j]; */
					environ[i] = replacestr;
					free(nne);
					/* free(replacestr); */
					return (0);
				}
			}
		}
		if (environ[i] == '\0')
		{
			if (val_new_env != NULL)
				replacestr = str_concat(nne, val_new_env);
			environ[i + 1] = '\0';
			/* for (j = 0; replacestr[j] != '\0'; j++) */
			/* 	environ[i][j] = replacestr[j]; */
			environ[i] = replacestr;
			free(nne);
			/* free(replacestr); */
			return (0);
		}
	}
	return (-1);
}
