#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/*Shell 0.1*/
int execute_command(char *command);


/*functions to make the code look harder*/
int _putchar(char c);
size_t _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *s);
char *_strtok(char *str, char *delim);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
#endif
