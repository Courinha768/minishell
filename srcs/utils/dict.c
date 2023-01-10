/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:48:48 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/10 09:05:04 by amaria-d         ###   ########.fr       */
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
