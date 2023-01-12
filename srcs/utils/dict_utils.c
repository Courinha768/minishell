/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:07:23 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/12 16:44:37 by amaria-d         ###   ########.fr       */
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
	size_t	pos;

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


/*
t_dict	*dict_pop(t_dict *dict, char *key)
{
	char	*popped;

	if (!(*dict))
		return (NULL);
	
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
*/
