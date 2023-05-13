#include "main.h"

/**
 * execute_command - Executes a command.
 * @command: The command to execute.
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_command(char *command)
{
	char **args, *token;
	int i = 0;
	pid_t pid;
	int status;

	args = malloc(sizeof(char *) * BUFFER_SIZE);
	if (!args)
		return (-1);

	token = _strtok(command, " ");
	while (token)
	{
		args[i] = _strdup(token);
		if (!args[i])
		{
			free(args);
			return (-1);
		}
		token = _strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;

	pid = fork();
	if (pid == -1)
	{
		free(args);
		return (-1);
	}

	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			free(args);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do
		{
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	free(args);
	return (0);
}
char *get_input(void)
{
	char *buffer = malloc(sizeof(char) * BUFFER_SIZE);
	ssize_t nread;

	if (buffer == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	nread = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	if (nread == -1)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}

	if (buffer[nread - 1] == '\n')
	{
		buffer[nread - 1] = '\0';
		nread--;
	}

	buffer = realloc(buffer, sizeof(char) * nread);
	if (buffer == NULL)
	{
		perror("realloc");
		exit(EXIT_FAILURE);
	}

	return (buffer);
}
