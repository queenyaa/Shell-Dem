#include "shell.h"

/**
 * add_ dvar_n - adds a variable at the end
 * of a r_var list.
 * @head: head of the linked list.
 * @lvar: length of the variable.
 * @val: value of the variable.
 * @lval: length of the value.
 * Return: address of the head.
 */
d_var *add_dvar_n(d_var **head, int dvar, char *wght, int dwght)
{
	d_var *nw, *tmp;

	nw = malloc(sizeof(d_var));
	if (nw == NULL)
		return (NULL);

	nw->dim_var = dvar;
	nw->wght = wght;
	nw->dim_wght = dwght;

	nw->fward = NULL;
	tmp = *head;

	if (tmp == NULL)
	{
		*head = nw;
	}
	else
	{
		while (tmp->fward != NULL)
			tmp = tmp->fward;
		tmp->fward = nw;
	}

	return (*head);
}

/**
 * free_dvar_list - frees a r_var list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_dvar_list(d_var **head)
{
	d_var *tmp;
	d_var *bind;

	if (head != NULL)
	{
		bind = *head;
		while ((tmp = bind) != NULL)
		{
			bind = bind->fward;
			free(tmp);
		}
		*head = NULL;
	}
}
