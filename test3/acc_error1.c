#include "shell.h"

/**
 * err_g_cd - error message for cd command in get_cd
 * @inpsh: data relevant (directory)
 * Return: Error message
 */
char *err_g_cd(inp_shell *inpsh)
{
	int lgth, lgth_id;
	char *err, *v_str, *note;

	v_str = acc_itoa(inpsh->sheep);
	if (inpsh->argt[1][0] == '-')
	{
		note = ": Illegal option ";
		lgth_id = 2;
	}
	else
	{
		note = ": can't cd to ";
		lgth_id = _strlen(inpsh->argt[1]);
	}

	lgth = _strlen(inpsh->avec[0]) + _strlen(inpsh->argt[0]);
	lgth += _strlen(v_str) + _strlen(note) + lgth_id + 5;
	err = malloc(sizeof(char) * (lgth + 1));

	if (err == 0)
	{
		free(v_str);
		return (NULL);
	}

	err = strcat_cd(inpsh, note, err, v_str);

	free(v_str);

	return (err);
}

/**
 * err_nfound - generic error message for command not found
 * @inpsh: data relevant (counter, arguments)
 * Return: Error message
 */
char *err_nfound(inp_shell *inpsh)
{
	int lgth;
	char *err;
	char *v_str;

	v_str = acc_itoa(inpsh->sheep);
	lgth = _strlen(inpsh->avec[0]) + _strlen(v_str);
	lgth += _strlen(inpsh->argt[0]) + 16;
	err = malloc(sizeof(char) * (lgth + 1));
	if (err == 0)
	{
		free(err);
		free(v_str);
		return (NULL);
	}
	_strcpy(err, inpsh->avec[0]);
	_strcat(err, ": ");
	_strcat(err, v_str);
	_strcat(err, ": ");
	_strcat(err, inpsh->argt[0]);
	_strcat(err, ": not found\n");
	_strcat(err, "\0");
	free(v_str);
	return (err);
}

/**
 * strcat_cd - function that concatenates the message for cd error
 *
 * @inpsh: data relevant (directory)
 * @note: message to print
 * @err: output message
 * @v_str: counter lines
 * Return: error message
 */
char *strcat_cd(inp_shell *inpsh, char *note, char *err, char *v_str)
{
	char *red_flag;

	_strcpy(err, inpsh->avec[0]);
	_strcat(err, ": ");
	_strcat(err, v_str);
	_strcat(err, ": ");
	_strcat(err, inpsh->argt[0]);
	_strcat(err, note);
	if (inpsh->argt[1][0] == '-')
	{
		red_flag = malloc(3);
		red_flag[0] = '-';
		red_flag[1] = inpsh->argt[1][1];
		red_flag[2] = '\0';
		_strcat(err, red_flag);
		free(red_flag);
	}
	else
	{
		_strcat(err, inpsh->argt[1]);
	}

	_strcat(err, "\n");
	_strcat(err, "\0");
	return (err);
}


/**
 * err_exit_shell - generic error message for exit in get_exit
 * @inpsh: data relevant (counter, arguments)
 *
 * Return: Error message
 */
char *err_exit_shell(inp_shell *inpsh)
{
	int lgth;
	char *err;
	char *v_str;

	v_str = acc_itoa(inpsh->sheep);
	lgth = _strlen(inpsh->avec[0]) + _strlen(v_str);
	lgth += _strlen(inpsh->argt[0]) + _strlen(inpsh->argt[1]) + 23;
	err = malloc(sizeof(char) * (lgth + 1));
	if (err == 0)
	{
		free(v_str);
		return (NULL);
	}
	_strcpy(err, inpsh->avec[0]);
	_strcat(err, ": ");
	_strcat(err, v_str);
	_strcat(err, ": ");
	_strcat(err, inpsh->argt[0]);
	_strcat(err, ": Illegal number: ");
	_strcat(err, inpsh->argt[1]);
	_strcat(err, "\n\0");
	free(v_str);

	return (err);
}
