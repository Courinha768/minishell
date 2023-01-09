/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:48:48 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/09 15:18:40 by amaria-d         ###   ########.fr       */
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