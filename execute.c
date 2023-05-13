include "main.h"

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
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    free(args);
    return (0);
}
