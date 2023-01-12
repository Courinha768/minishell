/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:07:23 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/16 16:42:52 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

/* Gets val referenced by key
 * Can return char * -> '\0'
 * if val hasn't been set yet
*/
char	*dict_get(t_dict *dict, char *key)
{
	size_t	i;
	size_t	whr;

	i = 0;
	while (i < dict->count)
	{
		whr = strcmpwhr(dict->env[i], key);
		if (dict->env[i][whr - 1] == '='
			&& key[whr - 1] == '\0')
			// && (key[whr - 1] == '=' || key[whr - 1] == '\0'))
			return (dict->env[i] + whr);
		i++;
	}
	return (NULL);
}

/**
 * Gets idx of env where char * is
 * Returns 0 on error so
 * return value is NOT idx:
 * 1 is first ([0]), 2 is second ([1]) ...
*/
size_t	dict_pos(t_dict *dict, char *key)
{
	size_t	i;
	size_t	whr;

	i = 0;
	while (i < dict->count)
	{
		whr = strcmpwhr(dict->env[i], key);
		if (dict->env[i][whr - 1] == '='
			&& key[whr - 1] == '\0')
			// && (key[whr - 1] == '=' || key[whr - 1] == '\0'))
			return (i + 1);
		i++;
	}
	return (0);
}

/**
 * Gets entire char * referenced by key
 * including key
*/
char	*dict_getit(t_dict *dict, char *key)
{
	size_t	pos;

	pos = dict_pos(dict, key);
	if (pos == 0)
		return (NULL);
	return(dict->env[pos - 1]);
}


void	d_iterprint(char *keyval)
{
	if (keyval)
		printf("%s\n", keyval);
}

void	dict_iter(t_dict *dict, void (*f)(char *))
{
	size_t	i;

	if (! dict)
		return ;
	i = 0;
	while (i < dict->count)
	{
		f(dict->env[i]);
		i++;
	}
}

// size_t	dictkeymin(t_dict *dict)
// {
// 	size_t	i;
// 	size_t	minidx;
// 	char	*min;

// 	i = 0;
// 	minidx = i;
// 	min = dict->key;
// 	// dict = dict->next;
// 	while (i < dict->count)
// 	{
// 		if (antstrcmp(dict->key, min) < 0)
// 		{
// 			minidx = i;
// 			min = dict->key;
// 		}
// 		i++;
// 		dict = dict->next;
// 	}
// 	return (minidx);
// }

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
