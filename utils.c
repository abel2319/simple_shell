#include "main.h"

/**
 * _strlen - get te length of a string
 * @str: string
 *
 * Return: the length of string
 */

int _strlen(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	return (1 + _strlen(str + 1));
}

/**
 * remove_end_line - remove \n to my string
 * @str: string to perform
 *
 */

void remove_end_line(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		if (str[i] == '\n')
			str[i] = '\0';

}
