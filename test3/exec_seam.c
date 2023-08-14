#include "shell.h"

/**
 * exec_line - finds builtins and commands
 *
 * @inpsh: data relevant (argt)
 * Return: 1 on success.
 */
int exec_line(inp_shell *inpsh)
{
	int (*builtin)(inp_shell *inpsh);

	if (inpsh->argt[0] == NULL)
		return (1);

	builtin = get_builtin(inpsh->argt[0]);

	if (builtin != NULL)
		return (builtin(inpsh));

	return (cmd_execut(inpsh));
}
