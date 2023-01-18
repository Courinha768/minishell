/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:48:48 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/18 20:43:30 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/include.h"

/* Creates and Intializes a new dict
 * For libft, could receive var
 * 0 will make it the default
 * else the var
*/
t_dict	dict_new(size_t amount)
{
	t_dict	new;
	//Alert: 2 mallocs!
	// new = malloc(sizeof(t_dict) * 1);
	if (amount == 0)
		amount = 500;
	new.env = malloc(amount * sizeof(char *));
	new.cap = amount;
	new.count = 0;
	return (new);
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
 * Inserts ALREADY malloc'ed keyval at index
*/
int	dict_append(t_dict *dict, char *keyval)
{
	if (keyval == NULL)
		return (0);
	if (dict->count >= dict->cap)
		dict_grow(dict);
	dict->env[dict->count] = keyval;
	dict->count++;
	return (1);
}

/**
 * Rmvs entry at given index
 * Pushes all next entries back to replace
*/
char	*dict_rmv(t_dict *dict, size_t index)
{
	char	*popped;

	if (!dict)
		return (NULL);
	popped = dict->env[index];

	while (index < dict->count - 1)
	{
		dict->env[index] = dict->env[index + 1];
		index++;
	}
	dict->env[index] = NULL;
	
	dict->count--; // Very important!
	return (popped);
}

char	*dict_pop(t_dict *dict, char *key)
{
	size_t	pos;

	if (!dict)
		return (NULL);
	pos = dict_pos(dict, key);
	if (pos == 0)
		return (NULL);
	return (dict_rmv(dict, pos - 1));
}
