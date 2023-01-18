/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:15:38 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/18 20:43:41 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/include.h"

/**
 * Does not presume '=' is inside keyval
 * Adds key-value pair to dict if new
 * Overwrites if new val is given
 * Receives keyval ALREADY malloc'ed
*/
int	dict_add(t_dict *dict, char *keyval)
{
	size_t	pos;

	if (keyval == NULL)
		return (0);
	pos = dict_pos(dict, keyval); // can all of keyval be used as key of pos?
	if (pos == 0)
		return (dict_append(dict, keyval));
	// In-Situ replace
	if (strichr(keyval, '='))
	{
		free(dict->env[pos - 1]);
		dict->env[pos - 1] = keyval;
		return (1);
	}
	// Did not add
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
		if (dict->env[i] != NULL)
			free(dict->env[i]);
		i++;
	}
	free(dict->env);
}
