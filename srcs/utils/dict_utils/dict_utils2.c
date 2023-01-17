/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:15:38 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/17 19:16:42 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/include.h"

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

/**
 * Inserts ALREADY malloc'ed keyval at index
*/
void	dict_insert(t_dict *dict, size_t index, char *keyval)
{
	dict->env[index] = keyval;
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
