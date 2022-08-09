#include "main.h"

/**
 * split_string - split a string for execve
 * @str: string to split
 * @del: delimiter for split
 *
 * Return: table of string split
 */

char **split_string(char *str, char *del)
{
	char *mystr, *buf;
	char **result;
	int size = 0, i;

	i = _strlen(str);

	mystr = malloc(sizeof(char) * (i + 1));

	for (i = 0; str[i] != '\0'; i++)
	{
		mystr[i] = str[i];
	}

	mystr[i] = '\0';

	buf = strtok(mystr, del);

	while (buf != NULL)
	{

		if (size == 0)
		{
			result = malloc(sizeof(char *) * ++size);
		}
		else
			result = realloc(result, sizeof(char *) * ++size);

		result[size - 1] = buf;
		buf = strtok(NULL, del);
	}


	result = realloc(result, sizeof(char *) * ++size);
	result[size - 1] = NULL;

	return (result);
}
