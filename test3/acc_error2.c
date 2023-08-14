#include "shell.h"

/**
 * err_path_126 - error message for path and failure denied permission.
 * @inpsh: data relevant (counter, arguments).
 *
 * Return: The error string.
 */
char *err_path_126(inp_shell *inpsh)
{
	int lgth;
	char *v_str;
	char *err;

	v_str = acc_itoa(inpsh->sheep);
	lgth = _strlen(inpsh->avec[0]) + _strlen(v_str);
	lgth += _strlen(inpsh->argt[0]) + 24;
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
	_strcat(err, ": Permission denied\n");
	_strcat(err, "\0");
	free(v_str);
	return (err);
}

/**
 * err_env - error message for env in get_env.
 * @inpsh: data relevant (counter, arguments)
 * Return: error message.
 */
char *err_env(inp_shell *inpsh)
{
	int lgth;
	char *err;
	char *v_str;
	char *note;

	v_str = acc_itoa(inpsh->sheep);
	note = ": Unable to add/remove from environment\n";
	lgth = _strlen(inpsh->avec[0]) + _strlen(v_str);
	lgth += _strlen(inpsh->argt[0]) + _strlen(note) + 4;
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
	_strcat(err, note);
	_strcat(err, "\0");
	free(v_str);

	return (err);
}
