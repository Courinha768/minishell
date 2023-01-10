/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictget_item.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:56:37 by amc               #+#    #+#             */
/*   Updated: 2023/01/10 17:01:14 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

size_t	dictsize(t_dict *dict)
{
	size_t	i;

	i = 0;
	while (dict)
	{
		dict = dict->next;
		i++;
	}
	return (i);
}

/**
 * Acts like python array[n]
 * Bizarre function. What happened??
 */
t_dict	*dictget_it(t_dict *dict, ssize_t index)
{
	int		size;
	int		i;

	if (index == 0)
		return (dict);
	if (index > 0)
	{
		while (index-- > 0)
			dict = dict -> next;
		return (dict);
	}
	if (index < 0)
		return (NULL);
	size = dictsize(dict);
	if (-index > size)
		return (NULL);
	i = 0;
	while (i < size + index)
	{
		dict = dict -> next;
		i++;
	}
	return (dict);
}
