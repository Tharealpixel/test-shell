#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

void display_prompt()
{
	printf("#cisfun$ ");
}

int main()
{
	char input[MAX_INPUT_LENGTH];
	int status;

	while (1)
	{
		display_prompt();
		if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
		{
			printf("\n");
			break;
		}
		input[strcspn(input, "\n")] = '\0'; // remove newline character
		pid_t pid = fork();
		if (pid == -1)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			// child process
			if (execl(input, input, (char *)NULL) == -1)
			{
				perror("execl failed");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			// parent process
			wait(&status);
			if (WIFEXITED(status))
			{
				int exit_status = WEXITSTATUS(status);
				if (exit_status != 0)
				{
					printf("%s: command not found\n", input);
				}
			}
			else if (WIFSIGNALED(status))
			{
				printf("%s: terminated by signal %d\n", input, WTERMSIG(status));
			}
		}
	}
	return 0;
}
