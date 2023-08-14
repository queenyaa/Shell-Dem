#include "shell.h"

/**
 * add_sig_tail - adds a separator found at the end
 * of a sep_list.
 * @head: head of the linked list.
 * @sig: separator found (; | &).
 * Return: address of the head.
 */
sig_list *add_sig_tail(sig_list **head, char sig)
{
	sig_list *nw, *tmp;

	nw = malloc(sizeof(sig_list));
	if (nw == NULL)
		return (NULL);

	nw->signal = sig;
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
 * free_sig_list - frees a sig_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_sig_list(sig_list **head)
{
	sig_list *tmp;
	sig_list *bind;

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

/**
 * add_dim_tail - adds a command line at the end
 * of a line_list.
 * @head: head of the linked list.
 * @seam: command line.
 * Return: address of the head.
 */
strlin_list *add_dim_tail(strlin_list **head, char *seam)
{
	strlin_list *nw, *tmp;

	nw = malloc(sizeof(strlin_list));
	if (nw == NULL)
		return (NULL);

	nw->seam = seam;
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
 * free_strlin_list - frees a line_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_strlin_list(strlin_list **head)
{
	strlin_list *tmp;
	strlin_list *bind;

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
