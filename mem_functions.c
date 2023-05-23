#include "main.h"

/**
 * _memcpy - Copy memory area
 * @dest: Pointer to the destination memory
 * @src: Pointer to the source memory
 * @n: Number of bytes to copy
 *
 * Return: Pointer to the destination memory
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *d = dest;
	const unsigned char *s = src;

	while (n--)
		*d++ = *s++;

	return (dest);
}

/**
 * _realloc - Reallocate memory block
 * @ptr: Pointer to the previously allocated memory block
 * @new_size: New size of the memory block
 *
 * Return: Pointer to the reallocated memory block, or NULL on failure
 */
void *_realloc(void *ptr, size_t new_size)
{
	void *new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
		return (malloc(new_size));

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	if (new_size > 0)
	{
		size_t copy_size = (new_size < sizeof(ptr)) ? new_size : sizeof(ptr);
		memcpy(new_ptr, ptr, copy_size);
	}

	free(ptr);
	return (new_ptr);
}
