#include "main.h"

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
	int test_read, status, test_exc, i = 0;
	char *cmd_pass = NULL;
	char **cmd = NULL;
	size_t char_read = 0;
	pid_t pid;

	do {

		write(1, "$ ", 2);
		test_read = getline(&cmd_pass, &char_read, stdin);

		if (test_read == -1)
			return (-1);

		remove_end_line(cmd_pass);

		cmd = split_string(cmd_pass, " ");

		cmd[0] = search_bin(cmd[0], _getenv("PATH"));

		if(cmd[0] != NULL){
			pid = fork();

			if (pid == -1)
				return (-1);
			else if (pid == 0)
			{
				i++;
				printf("pid son %u pid father %u\n", getpid(), getppid());
				test_exc = execve(cmd[0], cmd, env);

				if (test_exc == -1)
				{
					write(1, argv[0], _strlen(argv[0]));
					write(1, ": No such file or directory\n", 28);
				}
			}

			printf("status %u\n", wait(&status));

		}
	} while (test_read != -1);

	return (0);
}
