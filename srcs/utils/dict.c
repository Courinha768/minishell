/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:48:48 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/16 19:57:03 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

/* Creates and Intializes a new dict
 * For libft, could receive var
 * 0 will make it the default
 * else the var
*/
t_dict	dict_new(void)
{
	t_dict	new;
	//Alert: 2 mallocs!

	// new = malloc(sizeof(t_dict) * 1);
	new.env = malloc(500 * sizeof(char *));
	new.cap = 500;
	new.count = 0;
	return(new);
}

static void	dict_grow(t_dict *dict)
{
	char	**newenv;

	dict->cap = dict->cap + dict->cap / 2;
	
	newenv = malloc(sizeof(char *) * dict->cap);

	ft_memcpy(newenv, dict->env, dict->count * sizeof(char *));
	free(dict->env);
	dict->env = newenv;
}

/**
 * Adds key-value pair to dict
 * Does not presume '=' is inside keyval
 * Receives keyval ALREADY malloc'ed
*/
int	dict_add(t_dict *dict, char *keyval)
{
	//Alert: 2 mallocs. 1 is freed
	//TODO: not do 2 mallocs!
	size_t	i;

	if (keyval == NULL)
		return (0);
	i = 0;
	while (i < dict->count + 1)
	{
		if (dict->env[i] == NULL)
		{
			dict_insert(dict, i, keyval);
			return (1);
		}
		i++;
	}
	if (dict->count == dict->cap)
		dict_grow(dict);
	dict->env[dict->count] = keyval;
	dict->count++;

	return (1);
}

char	*dict_pop(t_dict *dict, char *key)
{
	char	*popped;
	size_t	pos;

	if (!dict)
		return (NULL);
	pos = dict_pos(dict, key);
	if (pop == 0)
		return (NULL);
	popped = dict->env[pos - 1];
	dict->env[pos - 1] = NULL; // very important!
	return (popped);
}

void	dict_shallowfree(t_dict *dict)
{
	free(dict->env);
	// free(dict);
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
	dict_shallowfree(dict);	
}

/**
 * Inserts ALREADY malloc'ed keyval at index
*/
void	dict_insert(t_dict *dict, size_t index, char *keyval)
{
	dict->env[index] = keyval;
}
