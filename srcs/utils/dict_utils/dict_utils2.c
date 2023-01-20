/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:15:38 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/20 05:44:15 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/include.h"

/**
 * Does not presume '=' is inside keyval
 * Adds key-value pair to dict if new
 * Overwrites (with free) if new val is given
 * Receives keyval ALREADY malloc'ed
*/
int	dict_add(t_dict *dict, char *keyval)
{
	size_t	pos;

	if (keyval == NULL)
		return (0);
	pos = dict_pos(dict, keyval);
	if (pos == 0)
		return (dict_append(dict, keyval));
	if (strichr(keyval, '='))
	{
		free(dict->env[pos - 1]);
		dict->env[pos - 1] = keyval;
		return (1);
	}
	return (0);
}

void	d_iterprint(char *keyval)
{
	if (keyval)
		printf("%s\n", keyval);
}

void	dict_iter(t_dict *dict, void (*f)(char *))
{
	size_t	i;

	i = 0;
	while (i < dict->count)
	{
		f(dict->env[i]);
		i++;
	}
}

/*

 Functional Paradigm
 * Inspired on mtrxdo
 * Replace t_dict with a struct that has a next-pointer
*/
void	dict_free(t_dict *dict)
{
	size_t	i;

	i = 0;
	while (i < dict->count)
	{
		free(dict->env[i]);
		i++;
	}
	free(dict->env);
}
