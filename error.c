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
		write(2, prg, _strlen(prg));
		write(2, ": 1: ", 5);
		write(2, bin_name, _strlen(bin_name));
		write(2, ": not found\n", 12);
	}
}
