#include "main.h"

char *_getenv(char *env)
{
	int i;
	char *env_key;

	for (i = 0; environ[i] != NULL; i++)
	{
		env_key = strtok(environ[i], "=");

		if ( check_equal_string(env, env_key) == 1)\
			return (strtok(NULL, "="));
	}

	return (NULL);
}
