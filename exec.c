#include "shell.h"

/**
 * handle_builtin - Handle Builtin Command
 * @cmd: Parsed Command
 * @st:status of last Excute
 * Return: -1 Fail 0 Succes (Excute status)
 */

int handle_builtin(char **cmd, int st)
{
	built_t builtin[] = {
		{"cd", change_dir},
		{"env", dis_env},
		{"help", dis_help},
		{"echo", echo_builtin},
		{"history", dis_history},
		{NULL, NULL}
	};
	int i = 0;

	while ((builtin + i)->command)
	{
		if (_strcmp(cmd[0], (builtin + i)->command) == 0)
		{
			return ((builtin + i)->fun(cmd, st));
		}
		i++;
	}
	return (-1);
}
/**
 * check_cmd - Excute Simple Shell Command (Fork,Wait,Excute)
 * @cmd:Parsed Command
 * @uinput: User Input
 * @c:Shell Excution Time Case of Command Not Found
 * @argv:Program Name
 * Return: 1 Case Command Null -1 Wrong Command 0 Command Excuted
 */
int check_cmd(char **cmd, char *uinput, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		{
			path_cmd(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(uinput);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
/**
 * signal_to_handle - Handle ^D
 * @sig: Signal
 * Return: Void
 */
void signal_to_handle(int sig)
{
	if (sig == SIGINT)
	{
		_PRINTF("\n#simple_shell$ ");
	}
}
