#include "shell.h"

/**
 * _strdup - duplicates a str in the heap memory.
 * @t: Type char pointer str
 * Return: duplicated str
 */
char *_strdup(const char *t)
{
	char *nw;
	size_t len;

	len = _strlen(t);
	nw = malloc(sizeof(char) * (len + 1));
	if (nw == NULL)
		return (NULL);
	_memcpy(nw, t, len + 1);
	return (nw);
}

/**
 * _strlen - Returns the lenght of a string.
 * @t: Type char pointer
 * Return: Always 0.
 */
int _strlen(const char *t)
{
	int len;

	for (len = 0; t[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * cmp_chars - compare chars of strings
 * @str: input string.
 * @shrt: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */
int cmp_chars(char str[], const char *shrt)
{
	unsigned int x, y, z;

	for (x = 0, z = 0; str[x]; x++)
	{
		for (y = 0; shrt[y]; y++)
		{
			if (str[x] == shrt[y])
			{
				z++;
				break;
			}
		}
	}
	if (x == z)
		return (1);
	return (0);
}

/**
 * _strtok - splits a string by some delimiter.
 * @str: input string.
 * @ short: delimiter.
 *
 * Return: string splited.
 */
char *_strtok(char str[], const char *shrt)
{
	static char *dvd, *str_l;
	char *str_b;
	unsigned int x, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, shrt))
			return (NULL);
		dvd = str; /*Store first address*/
		x = _strlen(str);
		str_l = &str[x]; /*Store last address*/
	}
	str_b = dvd;
	if (str_b == str_l) /*Reaching the end*/
		return (NULL);

	for (bool = 0; *dvd; dvd++)
	{
		/*Breaking loop finding the next token*/
		if (dvd != str_b)
			if (*dvd && *(dvd - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		for (x = 0; shrt[x]; x++)
		{
			if (*dvd == shrt[x])
			{
				*dvd = '\0';
				if (dvd == str_b)
					str_b++;
				break;
			}
		}
		if (bool == 0 && *dvd) /*Str != Delim*/
			bool = 1;
	}
	if (bool == 0) /*Str == Delim*/
		return (NULL);
	return (str_b);
}

/**
 * _isdigit - defines if string passed is a number
 *
 * @t: input string
 * Return: 1 if string is a number. 0 in other case.
 */
int _isdigit(const char *t)
{
	unsigned int x;

	for (x = 0; t[x]; x++)
	{
		if (t[x] < 48 || t[x] > 57)
			return (0);
	}
	return (1);
}
