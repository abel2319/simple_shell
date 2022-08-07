#include "main.h"

/**
 * main - entry point of shell
 *
 * Return: 0 for success
 */

int main(int __attribute__((unused))argc, char **argv)
{
	int test_read, status, i = 0, test_exc;
	char *cmd[] = {NULL, NULL};
	size_t char_read = 0;
	pid_t pid;

	do{
		write(1, "$ ", 2);
		test_read = getline(cmd, &char_read, stdin);

		if (test_read == -1)
			return (-1);

		for (i = 0; cmd[0][i] != '\0'; i++)
			if (cmd[0][i] == '\n')
				cmd[0][i] = '\0';

		pid = fork();

		if (pid == -1)
			return (-1);
		else if (pid == 0)
		{
			test_exc = execve(cmd[0], cmd, NULL);

			if (test_exc == -1)
			{
				write(1, argv[0], _strlen(argv[0]));
				write(1, ": No such file or directory\n", 28);
			}
		}
		else
		{
			wait(&status);
		}

	}while(test_read != -1);

	return (0);
}
