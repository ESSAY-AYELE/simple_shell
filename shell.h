#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *slice(char *str, int start, int end);
char **tokenize(char *input);
void loop(void);
char *read_line(int *);

void _memcpy(void *newptr, const void *ptr, unsigned int size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);
#endif
