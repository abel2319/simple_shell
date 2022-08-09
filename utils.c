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

/**
 * check_equal_string - verify if two strings are same
 * @str1: first strings
 * @str2: second string
 *
 * Return: 1 if str1 and str2 are same
 * 0 otherwize
 */

int check_equal_string(char *str1, char *str2)
{
	int i;

	for (i = 0; str1[i] != '\0'; i++)
		if (str2[i] == '\0' || (str1[i] != str2[i]))
			return (0);
				return (1);
}

/**
 * str_concat - concatenates two string
 * @s1: first string
 * @s2: second string
 *
 * Return: result string
 */

char *str_concat(char *s1, char *s2)
{
	int i, size = _strlen(s1) + _strlen(s2);
	char *new = malloc(sizeof(char) * (size + 1));

	if (new == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		if (i < _strlen(s1))
			new[i] = s1[i];
		else
			new[i] = s2[i - _strlen(s1)];
	}
	new[i] = '\0';
	return (new);
}


/**
 * _strdup - duplicate a string
 * @str: string to duplicate
 *
 * Return: pointer to the new string
 */

char *_strdup(char *str)
{
	int i, size = 0;
	char *new = NULL;

	if (str != NULL)
	{
		for (i = 0; str[i] != '\0'; size++, i++)
		{
		}

		new = malloc(sizeof(char) * (size + 1));

		if (new == NULL)
			return (NULL);

		for (i = 0; i < size + 1; i++)
			new[i] = str[i];

		return (new);
	}
	else
		return (NULL);
}
