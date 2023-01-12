/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:07:23 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/12 15:16:50 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

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
	char	*tmp;
	
	if (dict->count == dict->cap)
		dict_grow(dict);

	tmp = ft_strjoin("=", val);
	dict->env[dict->count] = ft_strjoin(key, tmp);
	free(tmp);
	dict->count++;
}


t_dict	*dict_pop(t_dict **dict, size_t	index)
{
	t_dict	*popped;

	if (!(*dict))
		return (NULL);
	if (index == 0)
	{
		popped = *dict;
		*dict = popped->next;
	}
	else
	{
		popped = dictget_it(*dict, index);
		dictget_it(*dict, index - 1)->next = popped->next;
	}
	popped->next = NULL;
	return (popped);
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
