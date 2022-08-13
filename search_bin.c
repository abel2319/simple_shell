#include "main.h"
/**
 * search_bin - search folder where executable bin is located
 * @bin: executable whose we're looking for
 * @path: string containing a whole of folder's path
 * where we will look for bin
 *
 * Return: absolute path of bin
 * NULL otherwize
 */
char *search_bin(char *bin, char *path)
{
	struct stat file;
	int test, test_cd;
	char *i_path, *save, *save1, *previous_path = NULL;

	test = stat(bin, &file);

	if (test == 0)
	{
		return (_strdup(bin));
	}

	previous_path = malloc(sizeof(char) * PATH_MAX);
	previous_path = getcwd(previous_path, PATH_MAX);
	i_path = strtok(path, ":");

	do {
		test_cd = chdir(i_path);
		if (test_cd == 0)
		{
			test = stat(bin, &file);

			if (test == 0)
			{
				chdir(previous_path);
				free(previous_path);
				save = str_concat(i_path, "/");
				save1 = str_concat(save, bin);
				free(save);
				return (save1);
			}
		}
		else
		{
			chdir(previous_path);
			free(previous_path);
			return (NULL);
		}

		i_path = strtok(NULL, ":");
	} while (test != 0);

	return (NULL);
}
