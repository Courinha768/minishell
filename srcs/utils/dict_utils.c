/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:07:23 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/10 17:07:52 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

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

t_dict	*dict_pop(t_dict **dict, size_t	index)
{
	t_dict	*popped;

	if (!(*dict))
		return (NULL);
	if (index == 0)
	{
		popped = *dict;
		*dict = popped->next;
	}
	else
	{
		popped = dictget_it(*dict, index);
		dictget_it(*dict, index - 1)->next = popped->next;
	}
	popped->next = NULL;
	return (popped);
}

void	dict_insert(t_dict **dict, size_t index, t_dict *new)
{
	t_dict	*before;

	if (!(*dict))
		return ;
	if (index == 0)
	{
		new->next = *dict;
		*dict = new;
		return ;
	}
	before = dictget_it(*dict, index - 1);
	new->next = before->next;
	before->next = new;
}
