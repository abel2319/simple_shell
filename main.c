#include "main.h"
/**
 * _myexec - execute binary in cmd[0]
 * @prg_name: our shell executable name
 * @cmd: commande to execute with its arguments
 * @env: environnement variable
 * @test: check if bin was found
 * Return: -1 if fork failed
 * 0 otherwize
 */
int _myexec(char *prg_name, char **cmd, char **env, int test)
{
	pid_t pid_prg;
	int status;

	if (test == 0)
	{
		pid_prg = fork();

		if (pid_prg == -1)
		{
			return (EXIT_FAILURE);
		}
		else if (pid_prg == 0)
		{
			execve(cmd[0], cmd, env);
		}

		wait(&status);
		free(cmd[0]);
	}
	else
	{
		display_error(prg_name, cmd[0]);
		free(cmd[0]);
		return (127);
	}

	return (EXIT_SUCCESS);
}

/**
 * main - Entry code
 * @argc: number of argument past to the num
 * @argv: arguments past to main
 * @env: environnemnt variable
 *
 * Return: 0 success
 * -1 otherwize
 */

int main(int __attribute__((unused)) argc, char **argv, char **env)
{
	ssize_t test_getline;
	size_t getline_count;
	char *line_cmd = NULL;
	char **cmd;
	char *path_s = NULL;
	int test_find, exit_stat = EXIT_SUCCESS;

	do {
		if (isatty(0))
			write(1, "$ ", 2);

		test_getline = getline(&line_cmd, &getline_count, stdin);

		if (test_getline == -1)
		{
			free(line_cmd);
			return (exit_stat);
		}

		remove_end_line(line_cmd);
		cmd = split_string(&line_cmd, " ");
		path_s = _getenv("PATH");

		cmd[0] = search_bin(cmd[0], path_s, &test_find);

		if (test_find != 1)
			exit_stat = _myexec(argv[0], cmd, env, test_find);

		if (path_s != NULL)
			free(path_s);
		free(cmd);
	} while (test_getline != -1);

	if (line_cmd != NULL)
		free(line_cmd);

	return (exit_stat);
}
