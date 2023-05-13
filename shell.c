#include "main.h"

#define PROMPT "#cisfun$ "

int main(void)
{
    char *input,*const argv[] = {input, NULL};
    size_t bufsize = 0;
    pid_t pid;

    while (1) {
        printf(PROMPT);
        if (getline(&input, &bufsize, stdin) == EOF) {
            printf("\n");
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        pid = fork();

        if (pid == -1) {
            perror("fork error");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            if (execve(input, argv, NULL) == -1) {
                perror("execve error");
            }
            exit(EXIT_FAILURE);
        } else {
            wait(NULL);
        }
    }

    free(input);

    return 0;
}

