#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define MAX_INPUT_LENGTH 1024
/*Shell 0.1*/
int execute_command(char *command);
char *get_input(void);


/*functions to make the code look harder*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/*Memory functions*/
void *_memcpy(void *dest, const void *src, size_t n);
void *_realloc(void *ptr, size_t new_size);

#endif
