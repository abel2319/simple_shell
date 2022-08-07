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
