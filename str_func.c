#include "shell.h"

/**
 * _strlen - length of a string
 * @s: pointer to a string
 * Return: the length of a string
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		continue;
	}
	return (i);
}

/**
 * _strdup - function to duplicate a string
 * @str: string
 * Return: pointer to duplicate string
 */

char *_strdup(char *str)
{
	size_t len, i;
	char *str2;

	len = _strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
		return (NULL);
	}

	i = 0;

       	while (i <= len)
	{
		str2[i] = str[i];
		i++;
	}

	return (str2);
}


