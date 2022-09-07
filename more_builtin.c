#include "shell.h"

/**
 * dis_history - Display History Of User Input Simple Shell
 * @c: Parsed Command
 * @s: Status of last execute command
 *
 * Return: 0 Succes -1 Fail
 *
 */

int dis_history(__attribute__((unused))char **c, __attribute__((unused))int s)
{
	char *filename = ".simple_shell_history";
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;
	char *er;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		er = _itoa(counter);
		_PRINTF(er);
		free(er);
		_PRINTF(" ");
		_PRINTF(line);
	}
	if (line)
		free(line);
	fclose(fp);
	return (0);
}

/**
 * print_echo - Excute Normal Echo
 * @cmd: Parsed Command
 *
 * Return: 0 Succes -1 Fail
 *
 */

int print_echo(char **cmd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/echo", cmd, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

/**
 * print_number -Print Unsigned Int Putchar
 * @n: Unisigned Integer
 * Return: Void
 */
void print_number(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
		print_number(x / 10);

	_putchar(x % 10 + '0');
}
/**
 * print_number_in -Print Number Putchar
 * @n:Integer
 * Return: void
 */
void print_number_in(int n)
{
	unsigned int x = n;

	if (n < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
		print_number(x / 10);
	_putchar(x % 10 + '0');
}
