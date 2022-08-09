#include "main.h"

char *search_bin(char *bin, char *path)
{
	struct stat file;
	int test, test_cd;
	char *i_path;
	char *previous_path = NULL;

	i_path = strtok(path, ":");

	test = stat(bin, &file);

	if (test == 0)
	{
		return bin;
	}

	previous_path = malloc(sizeof(char) * 2048);
	previous_path = getcwd(previous_path, 2048);
	do {
		test_cd = chdir(i_path);

		if (test_cd == 0)
		{
			test = stat(bin, &file);

			if (test == 0)
			{
				chdir(previous_path);
				free(previous_path);
				return (str_concat(str_concat(i_path, "/"), bin));
			}
		}
		else
			return (NULL);

		i_path = strtok(NULL, ":");
	} while (test != 0);

	return NULL;
}