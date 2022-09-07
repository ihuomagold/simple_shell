#include "shell.h"

/**
 * prerror - Print custom error
 * @argv:Program Name
 * @c:Error Count
 * @cmd: Command
 *
 * Return: Void
 *
 */

void prerror(char **argv, int c, char **cmd)
{
	char *er = _itoa(c);

	_PRINTF(argv[0]);
	_PRINTF(": ");
	_PRINTF(er);
	_PRINTF(": ");
	_PRINTF(cmd[0]);
	_PRINTF(": Illegal number: ");
	_PRINTF(cmd[1]);
	_PRINTF("\n");
	free(er);
}
