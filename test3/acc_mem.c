#include "shell.h"

/**
 * _memcpy - copies information between void pointers.
 * @n_ptr: destination pointer.
 * @ptr: source pointer.
 * @sz: size of the new pointer.
 *
 * Return: no return.
 */
void _memcpy(void *n_ptr, const void *ptr, unsigned int sz)
{
	char *char_ptr = (char *)ptr;
	char *char_n_ptr = (char *)n_ptr;
	unsigned int x;

	for (x = 0; x < sz; x++)
		char_n_ptr[x] = char_ptr[x];
}

/**
 * _realloc_ - reallocates a memory block.
 * @ptr: pointer to the memory previously allocated.
 * @o_sz: size, in bytes, of the allocated space of ptr.
 * @n_sz: new size, in bytes, of the new memory block.
 *
 * Return: ptr.
 * if n_sz == o_sz, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
void *_realloc_(void *ptr, unsigned int o_sz, unsigned int n_sz)
{
	void *n_ptr;

	if (ptr == NULL)
		return (malloc(n_sz));

	if (n_sz == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (n_sz == o_sz)
		return (ptr);

	n_ptr = malloc(n_sz);
	if (n_ptr == NULL)
		return (NULL);

	if (n_sz < o_sz)
		_memcpy(n_ptr, ptr, n_sz);
	else
		_memcpy(n_ptr, ptr, o_sz);

	free(ptr);
	return (n_ptr);
}

/**
 * _realloc_p - reallocates a memory block of a double pointer.
 * @ptr: double pointer to the memory previously allocated.
 * @o_sz: size, in bytes, of the allocated space of ptr.
 * @n_sz: new size, in bytes, of the new memory block.
 *
 * Return: ptr.
 * if n_sz == o_sz, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
char **_realloc_p(char **ptr, unsigned int o_sz, unsigned int n_sz)
{
	char **n_ptr;
	unsigned int x;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * n_sz));

	if (n_sz == o_sz)
		return (ptr);

	n_ptr = malloc(sizeof(char *) * n_sz);
	if (n_ptr == NULL)
		return (NULL);

	for (x = 0; x < o_sz; x++)
		n_ptr[x] = ptr[x];

	free(ptr);

	return (n_ptr);
}

