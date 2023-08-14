#include "shell.h"

/**
 * g_len - Get the lenght of a number.
 * @n: type int number.
 * Return: Lenght of a number.
 */
int g_len(int m)
{
	unsigned int m1;
	int lght = 1;

	if (m < 0)
	{
		lght++;
		m1 = m * -1;
	}
	else
	{
		m1 = m;
	}
	while (m1 > 9)
	{
		lght++;
		m1 = m1 / 10;
	}

	return (lght);
}

/**
 * acc_itoa - function converts int to string.
 * @m: type int number
 * Return: String.
 */
char *acc_itoa(int m)
{
	unsigned int m1;
	int lght = g_len(m);
	char *buff;

	buff = malloc(sizeof(char) * (lght + 1));
	if (buff == 0)
		return (NULL);

	*(buff + lght) = '\0';

	if (m < 0)
	{
		m1 = m * -1;
		buff[0] = '-';
	}
	else
	{
		m1 = m;
	}

	lght--;
	do {
		*(buff + lght) = (m1 % 10) + '0';
		m1 = m1 / 10;
		lght--;
	}
	while (m1 > 0)
		;
	return (buff);
}

/**
 * _atoi - converts a string to an integer.
 * @t: input string.
 * Return: integer.
 */
int _atoi(char *t)
{
	unsigned int flip = 0, sz = 0, mi = 0, mp = 1, p = 1, x;

	while (*(t + flip) != '\0')
	{
		if (sz > 0 && (*(t + flip) < '0' || *(t + flip) > '9'))
			break;

		if (*(t + flip) == '-')
			mp *= -1;

		if ((*(t + flip) >= '0') && (*(t + flip) <= '9'))
		{
			if (sz > 0)
				p *= 10;
			sz++;
		}
		flip++;
	}

	for (x = flip - sz; x < flip; x++)
	{
		mi = mi + ((*(t + x) - 48) * p);
		p /= 10;
	}
	return (mi * mp);
}
