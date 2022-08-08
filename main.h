#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int _strlen(char *str);
char **split_string(char *str, char *del);
void remove_end_line(char *str);

#endif /* _MAIN_H_ */
