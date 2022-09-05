#include "shell.h"

/**
 * _strcmp - Compare Two String
 * @s1: String 1
 * @s2: String 2
 *
 * Return: 0 If Identical Otherwise How Much Diffrent
 */

int _strcmp(char *s1, char *s2)
{
	int cmp = 0, i, len1, len2;
	len1 = _strlen(s1);
	len2 = _strlen(s2);

	if (s1 == NULL || s2 == NULL)
		return (1);
	if (len1 != len2)
		return (1);
	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			cmp = s1[i] - s2[i];
			break;
		}
		else
			continue;
	}
	return (cmp);
}

/**
 * _isalpha - Check if Alphabtic
 * @c: Character to be checked
 *
 * Return: 1 if c is a letter, lowercase or uppercase,
 * 0 if otherwise
 */

int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * _itoa - Convert Integer To Char
 * @n: Int To Convert
 *
 * Return: Char Pointer
 */

char *_itoa(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = intlen(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = (n % 10) + '0';
	array_rev(s, len);
	s[i + 1] = '\0';
	return (s);
}

/**
 * array_rev - Reverse Array
 * @arr: Array To Reverse
 * @len: Length Of Array to be reversed
 *
 * Return: Void(Reverse Array)
 */

void array_rev(char *arr, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}

/**
 * intlen - Determine Length Of Int
 * @num: Given Int
 *
 * Return: Length Of Int
 */

int intlen(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}
