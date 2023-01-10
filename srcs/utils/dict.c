/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:48:48 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/10 14:36:34 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

t_dict	*dict_new(char *key, char *val)
{
	t_dict	*head;
	
	head = malloc(sizeof(t_dict));
	if (!head)
		return (NULL);
	head->key = key;
	head->value = val;
	head->next = NULL;
	return (head);
}

int	dict_add(t_dict *dict, char *key, char *val)
{
	t_dict	*new;

	while (dict->next != NULL)
	{
		dict = dict->next;
	}
	new = malloc(sizeof(t_dict));
	if (!new)
		return (0);
	dict->next = new;
	new->key = key;
	new->value = val;
	new->next = NULL;
	return (1);
}

char	*dict_get(t_dict *dict, char *key)
{
	while (dict)
	{
		if (! strcmp(dict->key, key))
			return (dict->value);
		dict = dict->next;
	}
	return (NULL);
}

void	dict_iter(t_dict *dict, void (*f)(t_dict *))
{
	while (dict)
	{
		f(dict);
		dict = dict->next;
	}
}

size_t	dictkeymin(t_dict *dict)
{
	size_t	i;
	size_t	minidx;
	char	*min;

	i = 0;
	minidx = i;
	min = dict->key;
	// dict = dict->next;

	while (dict)
	{
		if (antstrcmp(dict->key, min) < 0)
		{
			minidx = i;
			min = dict->key;
		}
		i++;
		dict = dict->next;
	}
	return (minidx);
}

/* Functional Paradigm
 * Inspired on mtrxdo
 * Replace t_dict with a struct that has a next-pointer
*/
int	lstdo(t_dict **lst, t_dict **data, int (*func)(t_dict *, t_dict **, size_t))
{
	size_t	i;
	int		instant;
	int		accumulate;

	accumulate = 0;
	i = 0;
	while (*lst != NULL)
	{
		i++;
		instant = func(*lst, data, i);
		if (! instant)
		{
			return (0);
		}
		accumulate += instant;
		(*lst) = (*lst)->next;
	}
	return (accumulate);
}

static void	dict_freeone(t_dict *dict)
{
	free(dict->key);
	free(dict->value);
	free(dict);
}

void	dict_free(t_dict **dict)
{
	t_dict	*here;
	t_dict	*after;
	
	//TODO: Proctections
	here = *dict;
	while (here != NULL)
	{
		after = here->next;
		dict_freeone(here);
		here = after;
	}
}
