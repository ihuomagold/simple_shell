#include "shell.h"
<<<<<<< HEAD
/**
 * check_delim - Checks If A Character Match Any Char *
 * @c: Character To Check
 * @str: String To Check
 * Return: 1 Succes, 0 Failed
 */
unsigned int check_delim(char c, const char *str)
=======

/**
 * delim_check - Checks If A Character Matches Any Char *
 * @c: Character to be checked
 * @str: String To Check
 *
 * Return: 1 Success, 0 Fail
 */

unsigned int delim_check(char c, const char *str)
>>>>>>> 48f82fa4cd97283ad62d5f486c45b96f31ab8956
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}

/**
<<<<<<< HEAD
 * _strtok - Token A String Into Token (strtrok)
 * @str: String
 * @delim: Delimiter
 * Return: Pointer To The Next Token Or NULL
 */
=======
 * _strtok - Token A String Into Token (strtok)
 * @str: String
 * @delim: Delimiter
 *
 * Return: Pointer To The Next Token Or NULL
 */

>>>>>>> 48f82fa4cd97283ad62d5f486c45b96f31ab8956
char *_strtok(char *str, const char *delim)
{
	static char *ts;
	static char *nt;
	unsigned int i;

	if (str != NULL)
		nt = str;
	ts = nt;
	if (ts == NULL)
		return (NULL);
	for (i = 0; ts[i] != '\0'; i++)
	{
<<<<<<< HEAD
		if (check_delim(ts[i], delim) == 0)
=======
		if (delim_check(ts[i], delim) == 0)
>>>>>>> 48f82fa4cd97283ad62d5f486c45b96f31ab8956
			break;
	}
	if (nt[i] == '\0' || nt[i] == '#')
	{
		nt = NULL;
		return (NULL);
	}
	ts = nt + i;
	nt = ts;
	for (i = 0; nt[i] != '\0'; i++)
	{
<<<<<<< HEAD
		if (check_delim(nt[i], delim) == 1)
=======
		if (delim_check(nt[i], delim) == 1)
>>>>>>> 48f82fa4cd97283ad62d5f486c45b96f31ab8956
			break;
	}
	if (nt[i] == '\0')
		nt = NULL;
	else
	{
		nt[i] = '\0';
		nt = nt + i + 1;
		if (*nt == '\0')
			nt = NULL;
	}
	return (ts);
}
