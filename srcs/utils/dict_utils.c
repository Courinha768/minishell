/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:07:23 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/16 23:08:42 by amaria-d         ###   ########.fr       */
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

int	abs(int d)
{
	if (d < 0)
		return (-d);
	return (d);
}


size_t	strpos(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (0);

}

/**
 * Gets pos of env where char * is
 * Returns 0 on error so
 * return value is NOT idx:
 * 1 is first ([0]), 2 is second ([1]) ...
*/
size_t	dict_pos(t_dict *dict, char *key)
{
	//TODO: Not working:
	size_t	i;
	size_t	whr;
	// size_t	mlen;
	int		cmp;
	size_t	eqpos;

	i = 0;
	while (i < dict->count)
	{
		whr = strcmpwhr(dict->env[i], key);

		cmp = abs(ft_strncmp(dict->env[i], key, whr));
		if (cmp == 0 || cmp == '=')
			return (i + 1);

		eqpos = strpos(dict->env[i], '=');

		if (eqpos < whr)
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
	return (dict->env[pos - 1]);
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
