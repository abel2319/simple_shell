#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
		execve(argv[1], argv + 1, NULL);
	else
	{
		wait(&status);
		printf("Never display\n");
	}

	return (0);
}
