#include "main.h"

/**
 * display_error - print our shell errors
 * @prg: our shell
 * @bin_name: bin which failed
 *
 */

void display_error(char *prg, char *bin_name)
{
	if (bin_name != NULL)
	{
		write(1, prg, _strlen(prg));
		write(1, ": 1: ", 5);
		write(1, bin_name, _strlen(bin_name));
		write(1, ": not found\n", 12);
	}
}
