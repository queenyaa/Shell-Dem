#include "shell.h"

/**
 * rep_char - counts the repetitions of a char
 *
 * @intk: input string
 * @x: index
 * Return: repetitions
 */
int rep_char(char *intk, int x)
{
	if (*(intk - 1) == *intk)
		return (rep_char(intk - 1, x + 1));

	return (x);
}

/**
 * err_sig_op - finds syntax errors
 *
 * @intk: input string
 * @x: index
 * @last: last char read
 * Return: index of error. 0 when there are no
 * errors
 */
int err_sig_op(char *intk, int x, char last)
{
	int flip;

	flip = 0;
	if (*intk == '\0')
		return (0);

	if (*intk == ' ' || * intk == '\t')
		return (err_sig_op(intk + 1, x + 1, last));

	if (*intk == ';')
		if (last == '|' || last == '&' || last == ';')
			return (x);

	if (*intk == '|')
	{
		if (last == ';' || last == '&')
			return (x);

		if (last == '|')
		{
			flip = rep_char(intk, 0);
			if (flip == 0 || flip > 1)
				return (x);
		}
	}

	if (*intk == '&')
	{
		if (last == ';' || last == '|')
			return (x);

		if (last == '&')
		{
			flip = rep_char(intk, 0);
			if (flip == 0 || flip > 1)
				return (x);
		}
	}

	return (err_sig_op(intk + 1, x + 1, * intk));
}

/**
 * fir_char - finds index of the first char
 *
 * @ intk: input string
 * @x: index
 * Return: 1 if there is an error. 0 in other case.
 */
int fir_char(char *intk, int *x)
{

	for (*x = 0; intk[*x]; *x += 1)
	{
		if (intk[*x] == ' ' || intk[*x] == '\t')
			continue;

		if (intk[*x] == ';' || intk[*x] == '|' || intk[*x] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * pr_syntx_err - prints when a syntax error is found
 *
 * @inpsh: data structure
 * @intk: input string
 * @x: index of the error
 * @bool: to control msg error
 * Return: no return
 */
void pr_syntx_err(inp_shell * inpsh, char *intk, int x, int bool)
{
	char *note, *note2, *note3, *err, *sheep;
	int lgth;

	if (intk[x] == ';')
	{
		if (bool == 0)
			note = (intk[x + 1] == ';' ? ";;" : ";");
		else
			note = (intk[x - 1] == ';' ? ";;" : ";");
	}

	if (intk[x] == '|')
		note = (intk[x + 1] == '|' ? "||" : "|");

	if (intk[x] == '&')
		note = (intk[x + 1] == '&' ? "&&" : "&");

	note2 = ": Syntax error: \"";
	note3 = "\" unexpected\n";
	sheep = acc_itoa(inpsh->sheep);
	lgth = _strlen(inpsh->avec[0]) + _strlen(sheep);
	lgth += _strlen(note) + _strlen(note2) + _strlen(note3) + 2;

	err = malloc(sizeof(char) * (lgth + 1));
	if (err == 0)
	{
		free(sheep);
		return;
	}
	_strcpy(err, inpsh->avec[0]);
	_strcat(err, ": ");
	_strcat(err, sheep);
	_strcat(err, note2);
	_strcat(err, note);
	_strcat(err, note3);
	_strcat(err, "\0");

	write(STDERR_FILENO, err, lgth);
	free(err);
	free(sheep);
}

/**
 * chk_syntx_err - intermediate function to
 * find and print a syntax error
 *
 * @inpsh: data structure
 * @intk: input string
 * Return: 1 if there is an error. 0 in other case
 */
int chk_syntx_err(inp_shell *inpsh, char *intk)
{
	int now = 0;
	int h_char = 0;
	int x = 0;

	h_char = fir_char(intk, &now);
	if (h_char == -1)
	{
		pr_syntx_err(inpsh, intk, now, 0);
		return (1);
	}

	x = err_sig_op(intk + now, 0, *(intk + now));
	if (x != 0)
	{
		pr_syntx_err(inpsh, intk, now + x, 1);
		return (1);
	}

	return (0);
}
