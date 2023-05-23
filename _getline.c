#include "main.h"

#define DEFAULT_BUFFER_SIZE 128

/**
 * _getline - Custom getline function
 * @bufline: Double pointer to the buffer storing the line
 * @size: Pointer to the size of the buffer
 * @stream: File stream to read from
 *
 * Return: Number of characters read, or -1 on failure
 */
ssize_t _getline(char **bufline, size_t *size, FILE *stream)
{
	size_t i = 0, new_size;
        int c;
	char *new_line;

	if (!bufline || !size || !stream)
		return (-1);

	if (*bufline == NULL)
	{
		*size = DEFAULT_BUFFER_SIZE;
		*bufline = (char *)malloc(*size);
		if (*bufline == NULL)
			return (-1);
	}

	while ((c = fgetc(stream)) != EOF)
	{
		if (i >= *size - 1)
		{
			new_size = *size * 2;
			new_line = (char *)_realloc(*bufline, new_size);
			if (new_line == NULL)
				return (-1);

			*bufline = new_line;
			*size = new_size;
		}

		(*bufline)[i++] = (char)c;

		if (c == '\n')
			break;
	}

	if (i == 0)
		return (-1);

	(*bufline)[i] = '\0';
	return (i);
}
