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
	char *temp, *buf, *temp1;

	for (i = 0; environ[i] != NULL; i++)
	{
		temp = _strdup(environ[i]);

		env_key = strtok(temp, "=");

		if (check_equal_string(env, env_key) == 1)
		{
			buf = strtok(NULL, "=");
			temp1 = _strdup(buf);
			free(temp);
			return (temp1);
		}

		free(temp);
	}

	return (NULL);
}
