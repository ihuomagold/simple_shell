#include "shell.h"

/**
 * prompt - Display Shell Prompt
 */
void prompt(void)
{
	_PRINTF("#simple_shell$ ");
}
/**
 * print_error - Display Error Based on Command and How Many Time Shell Looped
 * @input:User Input
 * @counter:Simple Shell Count Loop
 * @argv:Program Name
 * Return: Void
 */
void print_error(char *input, int counter, char **argv)
{
	char *er;

	_PRINTF(argv[0]);
	_PRINTF(": ");
	er = _itoa(counter);
	_PRINTF(er);
	free(er);
	_PRINTF(": ");
	_PRINTF(input);
	_PRINTF(": not found\n");
}
