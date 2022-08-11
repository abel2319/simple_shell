#include "main.h"

/**
 * _execve - execute commande specified by cmd
 * @cmd: commande to execute
 * @argv: second argument in function main
 * @env: third argument in function main
 *
 * Return: 1 id success
 * -1 otherwize
 */

int _execve(char **cmd, char **argv, char **env)
{
	int status;
	pid_t pid;

	if (cmd[0] != NULL)
	{
		pid = fork();

		if (pid == -1)
			return (-1);
		else if (pid == 0)
		{

			execve(cmd[0], cmd, env);

		}

		wait(&status);
		free(cmd[0]);

	}

	return (1);
}

/**
 * main - entry point of shell
 *
 * @argc: number of argument
 * @argv: argument list
 * @env: list of env var
 *
 * Return: 0 for success
 */

int main(int __attribute__((unused))argc, char **argv, char **env)
{
	int test_read, test_exc, test_verif;
	char *cmd_pass = NULL;
	char **cmd = NULL;
	size_t char_read = 0;

	do {
		/* write(1, "$ ", 2); */
		cmd_pass = NULL;
		test_read = getline(&cmd_pass, &char_read, stdin);

		if (test_read == -1)
			return (-1);

		remove_end_line(cmd_pass);

		if (cmd != NULL)
			free(cmd);

		cmd = split_string(cmd_pass, " ");

		test_verif = check_equal_string(cmd[0], "exit");
		if (test_verif)
			_exit(1);

		if (cmd_pass != NULL)
			free(cmd_pass);

		cmd[0] = search_bin(cmd[0], _getenv("PATH"), arv[0]);

		test_exc = _execve(cmd, argv, env);
		if (test_exc == -1)
			return (-1);

	} while (test_read != -1);

	return (0);
}
