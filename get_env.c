#include "main.h"

/**
 * _getenv - get value of env variable
 * @env: env to get
 *
 * Return: value of env
 */

char *_getenv(char *env)
{
	int i;
	char *env_key;
	char *temp, *buf;

	for (i = 0; environ[i] != NULL; i++)
	{
		temp = _strdup(environ[i]);

		env_key = strtok(temp, "=");

		if (check_equal_string(env, env_key) == 1)
		{
			buf = strtok(NULL, "=");
			/* free(temp); */
			return (buf);
		}

		free(temp);
	}

	return (NULL);
}
