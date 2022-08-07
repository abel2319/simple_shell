#include "main.h"
/**
 * _split - split the string got by getline
 * @str: string to split using space as delimiter
 *
 * Return: an array of string
 */
void _split(char *str[])
{
	char *token;
	int len = 0, i = 0, j = 0;

	len = _strlen(*str) + 1;
	for (; i <= len; i++)
	{
		/*tmp[i] = str[0][i];*/
		if (str[0][i] == ' ' && str[0][i + 1] != ' ')
			j++;
	}

	i=0;
	token = strtok(str[0], " ");
	str = realloc(str, sizeof(char*) * j);
	while (token != NULL)
	{
		len = _strlen(token) + 1;
		str[i] = malloc(sizeof(char) * len);

		for (j = 0; j <= len; j++)
			str[0][j] = token[j];

		i++;
		token = strtok(NULL, " ");
	}
}
