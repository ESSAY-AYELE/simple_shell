#ifndef SHELL_H
#define SHELL_H

#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

typedef struct builtin_s
{
	char *name;
	int (*f)(char **);
} builtin_t;

extern char **environ;
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

int is_cdir(char *path, int *i);
char *_which(char *cmd);
int is_executable(char *);
int check_error_cmd(char *dir, char **);
int cmd_exec(char **);

char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);


int exec_line(char **cmd);

char *_getenv(const char *name, char **_environ);
int _env(char **);

int (*get_builtin(char *cmd))(char **);


int _atoi(char *s);
int exit_shell(char **cmd);
#endif
