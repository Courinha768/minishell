/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:48:48 by amaria-d          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/16 16:44:24 by amaria-d         ###   ########.fr       */
=======
/*   Updated: 2023/01/14 19:23:20 by amaria-d         ###   ########.fr       */
>>>>>>> Finished alpha-ordering of shexport but afinal isn't how the real one
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
	new->env = malloc(500 * sizeof(char *));
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
	size_t	i;

	i = 0;
	while (i < dict->count + 1)
	{
		if (dict->env[i] == NULL)
		{
			if (val == NULL)
				tmp = ft_strjoin("=", "''");
			else
				tmp = ft_strjoin("=", val);
			dict->env[i] = ft_strjoin(key, tmp);
			free(tmp);
			dict->count++;
			return (1);			
		}
		i++;
	}
	if (dict->count == dict->cap)
		dict_grow(dict);

	if (val == NULL)
		tmp = ft_strjoin("=", "''");
	else
		tmp = ft_strjoin("=", val);
	dict->env[dict->count] = ft_strjoin(key, tmp);
	free(tmp);
	dict->count++;

	return (1);
}

char	*dict_pop(t_dict *dict, char *key)
{
	char	*popped;
	size_t	whr;

	if (!dict)
		return (NULL);
	whr = dict_pos(dict, key);
	popped = dict->env[whr - 1];
	dict->env[whr - 1] = NULL; // very important!
	return (popped);
}

void	dict_shallowfree(t_dict *dict)
{
	free(dict->env);
	free(dict);
}
/*
 Functional Paradigm
 * Inspired on mtrxdo
 * Replace t_dict with a struct that has a next-pointer

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

/*
void	dict_insert(t_dict **dict, size_t index, t_dict *new)
{
	t_dict	*before;

	if (!(*dict))
		return ;
	if (index == 0)
	{
		new->next = *dict;
	fixed dict_add to make it work
c282784 Revamped the base funcs for t_dict. I should make a t_array struct to further abstract. Hv to add pop
881bfe0 In the middle of implementing dict_get
180796c Starting the re-implementation of dict as an array stylebefore = dictget_it(*dict, index - 1);
	new->next = before->next;
	before->next = new;
}
*/
