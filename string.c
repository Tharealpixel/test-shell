#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * _strlen - Returns the length of a string.
 * @s: The string to get the length of.
 *
 * Return: The length of the string.
 */
size_t _strlen(char *s)
{
	size_t len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: 0 if s1 and s2 are equal, otherwise the difference
 * between the ASCII values of the first non-matching characters.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
		s1++, s2++;

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * _strdup - Duplicates a string.
 * @s: The string to duplicate.
 *
 * Return: A pointer to the newly-allocated duplicated string,
 * or NULL if memory allocation fails.
 */
char *_strdup(char *s)
{
	size_t len = _strlen(s) + 1;
	char *dup = malloc(sizeof(char) * len);

	if (dup)
		memcpy(dup, s, len);

	return (dup);
}

/**
 * _strtok - Breaks a string into tokens.
 * @str: The string to tokenize.
 * @delim: The delimiter to use to tokenize the string.
 *
 * Return: A pointer to the first token found, or NULL if no token is found.
 */
char *_strtok(char *str, char *delim)
{
	static char *last;
	char *token;
	char *delim_set;

	if (str)
		last = str;

	if (!*last)
		return (NULL);

	token = last;

	while (*last)
	{
		delim_set = delim;

		while (*delim_set)
		{
			if (*last == *delim_set)
			{
				*last = '\0';
				last++;
				return (token);
			}

			delim_set++;
		}

		last++;
	}

	return (token);
}
