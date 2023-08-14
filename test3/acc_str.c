#include "shell.h"

/**
 * _strcat - concatenate two strings
 * @des: char pointer the dest of the copied str
 * @sr: const char pointer the source of str
 * Return: the des
 */
char *_strcat(char *des, const char *sr)
{
	int x;
	int y;

	for (x = 0; des[x] != '\0'; x++)
		;

	for (y = 0; sr[y] != '\0'; y++)
	{
		des[x] = sr[y];
		x++;
	}

	des[x] = '\0';
	return (des);
}

/**
 * *_strcpy - Copies the string pointed to by src.
 * @des: Type char pointer the dest of the copied str
 * @sr: Type char pointer the source of str
 * Return: the dest.
 */
char *_strcpy(char *des, char *sr)
{

	size_t ad;

	for (ad = 0; sr[ad] != '\0'; ad++)
	{
		des[ad] = sr[ad];
	}
	des[ad] = '\0';

	return (des);
}

/**
 * _strcmp - Function that compares two strings.
 * @t1: type str compared
 * @t2: type str compared
 * Return: Always 0.
 */
int _strcmp(char *t1, char *t2)
{
	int x;

	for (x = 0; t1[x] == t2[x] && t1[x]; x++)
		;

	if (t1[x] > t2[x])
		return (1);
	if (t1[x] < t2[x])
		return (-1);
	return (0);
}

/**
 * _strchr - locates a character in a string,
 * @t: string.
 * @c: character.
 * Return: the pointer to the first occurrence of the character c.
 */
char *_strchr(char *t, char c1)
{
	unsigned int x = 0;

	for (; *(t + x) != '\0'; x++)
		if (*(t + x) == c1)
			return (t + x);
	if (*(t + x) == c1)
		return (t + x);
	return ('\0');
}

/**
 * _strspn - gets the length of a prefix substring.
 * @t: initial segment.
 * @take: accepted bytes.
 * Return: the number of accepted bytes.
 */
int _strspn(char *t, char *take)
{
	int x, y, bool;

	for (x = 0; *(t + x) != '\0'; x++)
	{
		bool = 1;
		for (y = 0; *(take + y) != '\0'; y++)
		{
			if (*(t + x) == *(take + y))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (x);
}
