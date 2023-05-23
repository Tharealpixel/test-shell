#include "main.h"

int main()
{
        char *buff = NULL;
        size_t buff_size = 0;
        char *token, **arr;
        int status, i = 0;
        pid_t pid;

        while (1)
        {
                write(1, "#cisfun$ ", 9);
		_getline(&buff, &buff_size, stdin);
                arr = malloc(sizeof(char *) * 1024);
                token = strtok(buff, " \n\t");
                while (token)
                {
                        arr[i] = token;
                        token = strtok(NULL, " \n\t");
                        i++;
                }
                arr[i] = NULL;
                pid = fork();
                if (pid == 0)
                {
                        if (execve(arr[0], arr, NULL) == -1)
			{
                                perror("exceve");
				exit(0);
			}
                }
                else
                        wait(&status);

                i = 0;
                free(arr);
        }
	return (0);
}
