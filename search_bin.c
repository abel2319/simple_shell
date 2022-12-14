#include "main.h"

/**
 * set_correct_path - set the correct path of bin if found on PATH
 * @previous_path: current path of th program
 * @bin: name of bin
 * @i_path: PATH found
 *
 * Return: correct path
 */

char *set_correct_path(char *previous_path, char *bin, char *i_path)
{
	char *save, *save1;

	chdir(previous_path);
	free(previous_path);
	save = str_concat(i_path, "/");
	save1 = str_concat(save, bin);
	free(save);

	return (save1);
}

/**
 * search_bin - search folder where executable bin is located
 * @bin: executable whose we're looking for
 * @path: string containing a whole of folder's path
 * where we will look for bin
 * @test_f: test if bin is found
 *
 * Return: absolute path of bin
 */

char *search_bin(char *bin, char *path, int *test_f)
{
	struct stat file;
	int test;
	char *i_path, *previous_path = NULL;

	if (bin == NULL)
	{
		*test_f = 1;
		return (_strdup(bin));
	}
	test = stat(bin, &file);
	if (test == 0)
	{
		*test_f = 0;
		return (_strdup(bin));
	}
	if (path == NULL)
	{
		*test_f = -1;
		return (_strdup(bin));
	}
	previous_path = malloc(sizeof(char) * PATH_MAX);
	previous_path = getcwd(previous_path, PATH_MAX);
	i_path = strtok(path, ":");
	while (i_path != NULL && path != NULL)
	{
		chdir(i_path);
		test = stat(bin, &file);
		if (test == 0)
		{
			*test_f = 0;
			return (set_correct_path(previous_path, bin, i_path));
		}
		i_path = strtok(NULL, ":");
	}
	chdir(previous_path);
	free(previous_path);
	*test_f = -1;

	return (_strdup(bin));
}
