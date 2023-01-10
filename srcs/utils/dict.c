/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:48:48 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/10 17:07:48 by aappleto         ###   ########.fr       */
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
