#include "main.h"
/**
 * find_number_token - find number of token in a string
 * by using the delimatator(s)
 * @str: where token are counted
 * @del: hte delimator(s)
 * @index : if a token is counted or not
 *
 * Return: the number of token
 * Or 0 if nothing is found
 */
int find_number_token(char *str, char *del, int index)
{
	int j;

	if (*str == '\0')
		return (0);

	for (j = 0; j < _strlen(del); j++)
	{
		if (*str == del[j])
		{
			return (0 + find_number_token(str + 1, del, 0));
		}
	}

	if (index == 1)
		return (0 + find_number_token(str + 1, del, 1));

	return (1 + find_number_token(str + 1, del, 1));
}

/**
 * split_string - split a string for execve
 * @str: string to split
 * @del: delimiter for split
 *
 * Return: table of string split
 */

char **split_string(char **str, char *del)
{
	char **result = NULL;
	int i = 0, count = 0;

	if (str == NULL)
		return (NULL);

	count = find_number_token(*str, del, 0);
	result = malloc(sizeof(char *) * (count + 1));

	result[i] = strtok(*str, " ");

	while (result[i] != NULL)
		result[++i] = strtok(NULL, " ");
	return (result);
}
