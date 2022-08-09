#include "main.h"

char *_getenv(char *env)
{
	int i;
	char *env_key;
	char *temp;

	for (i = 0; environ[i] != NULL; i++)
	{
		temp = _strdup(environ[i]);

		env_key = strtok(temp, "=");

		if ( check_equal_string(env, env_key) == 1)
			return (strtok(NULL, "="));
	}

	return (NULL);
}
