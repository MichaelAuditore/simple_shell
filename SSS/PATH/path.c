#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

/**
 * _strcmp - compare character for character betwen two string and if find a
 * diferente character , minus both chracters and convert in ascii.
 * @s2: String to kill
 * @s1: string to replance
 * Return: The string replaced
 */
int _strcmp(char *s1, char *s2)
{
	int a, res;

	res = 0;
	for (a = 0; s1[a] != '\0'; a++)
	{
		if (s1[a] != s2[a])
		{
			res = s1[a] - s2[a];
			break;
		}
	}
	if (s2[a] != '\0')
		return (1);
	return (res);
}
/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	int i, boll = 0;
	DIR *dir;
	struct dirent *pDirent;
	char *command = "_which";

	if (ac < 3)
	{
		printf("Put all the parameters: _which and the filename to search\n");
		return (1);
	}
	if ((_strcmp(av[1], command)) == 0)
	{
		dir = opendir(".");
		if (dir == NULL)
		{
			printf ("Cannot open directory '%s'\n", av[1]);
			return (1);
		}
		else
		{
			while ((pDirent = readdir(dir)) != NULL)
			{
				i = 0;
				while (av[i] != NULL)
				{
					if ((_strcmp(av[i], pDirent->d_name)) == 0)
					{
						printf ("[%s]\n", pDirent->d_name);
						boll = 1;
					}
					i++;
				}
			}
			closedir (dir);
			if (boll == 1)
				return (0);
			printf("Not find the filename\n");
		}
	}
	else
		printf("Pls put the command _which correctly\n");
	return (1);
}
