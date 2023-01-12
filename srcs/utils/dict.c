/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:48:48 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/12 16:24:56 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

/* Creates and Intializes a new dict
 * For libft, could receive var
 * 0 will make it the default
 * else the var
*/
t_dict	*dict_new(void)
{
	t_dict	*new;
	//Alert: 2 mallocs!
	
	new = malloc(sizeof(t_dict) * 1);
	new->env = ft_calloc(500, sizeof(char *)); // very important to calloc
	new->cap = 500;
	new->count = 0;
	return(new);
}

void	dict_grow(t_dict *dict)
{
	char	**newenv;

	dict->cap = dict->cap + dict->cap / 2;
	
	newenv = malloc(sizeof(char *) * dict->cap);

	ft_memcpy(newenv, dict->env, dict->count * sizeof(char *));
	free(dict->env);
	dict->env = newenv;
}

int	dict_add(t_dict *dict, char *key, char *val)
{
	//Alert: 2 mallocs. 1 is freed
	//TODO: not do 2 mallocs!
	char	*tmp;
	
	if (dict->count == dict->cap)
		dict_grow(dict);

	tmp = ft_strjoin("=", val);
	dict->env[dict->count] = ft_strjoin(key, tmp);
	free(tmp);
	dict->count++;

	return (1);
}


/*
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
*/

/*
 Functional Paradigm
 * Inspired on mtrxdo
 * Replace t_dict with a struct that has a next-pointer

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
}*/
