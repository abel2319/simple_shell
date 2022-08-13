#ifndef _MAIN_H_
#define _MAIN_H_

#define _GNU_SOURCE

#include <linux/limits.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int _strlen(char *str);
char **split_string(char **str, char *del);
void remove_end_line(char *str);
char *search_bin(char *, char *);
int check_equal_string(char *str1, char *str2);
char *_getenv(char *env);
char *str_concat(char *s1, char *s2);
char *_strdup(char *str);
void display_error(char *, char *);

#endif /* _MAIN_H_ */
