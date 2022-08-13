#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[], char **env)
{
	//_exit(1);
	printf("%s", env[0]);
}
