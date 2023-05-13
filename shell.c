#include "main.h"

void display_prompt()
{
	printf("#cisfun$ ");
}

int main(void)
{
	pid_t pid;
	char *line;

	while (1)
	{
		printf("#cisfun$ ");
		line = read_line();

		pid = fork();
		if (pid < 0)
		{
			perror("fork error");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			/* child process */
			execve(line, NULL, environ);
			perror("execve error");
			exit(EXIT_FAILURE);
		}
		else
		{
			/* parent process */
			wait(NULL);
		}

		free(line);
	}

	return EXIT_SUCCESS;
}

char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t linelen = getline(&line, &bufsize, stdin);
	if (linelen == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	return line;
}
