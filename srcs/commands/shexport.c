/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shexport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:16:24 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/14 20:04:26 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

size_t	ft_min(size_t a, size_t b)
{
	if (b < a)
		return (b);
	return (a);
}

void	ft_strswap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

/* Gives pos where the char is
 * Not idx! 0 is not-found: 1 is first ([0])
 * 2 is second ([1]) ...
*/
size_t	strichr(const char *s, int c)
{
	size_t  i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i + 1);
		i++;
	}
	return (0);
}


void	dictorderalpha(t_dict *dict)
{
	size_t	j;
	size_t	i;
	char	**min;
	size_t	whr;

	j = 0;
	while (j < dict->count)
	{
		min = &dict->env[j];
		whr = strichr(*min, '=');
		i = j + 1;
		while (i < dict->count / 2 + 1)
		{
			whr = ft_min(whr, strichr(dict->env[i], '='));
			if (strncmp(*min, dict->env[i], whr) > 0)
			{
				ft_strswap(min, &(dict->env[i]));
				whr = strichr(*min, '=');
			}
			i++;
		}
		j++;
	}
}

/**
 * Export with no options
*/
int	func_export(t_command command, t_promptinfo *prompt)
{
	t_dict	shexport;

	if (ft_mtrxlen((void **)command.args) < 1)
	{
		// Only order-alpha and print
		shexport.env = malloc(sizeof(char *) * prompt->shenv->count);
		ft_memcpy(shexport.env, prompt->shenv->env, prompt->shenv->count * sizeof(char *));
		shexport.cap = prompt->shenv->count;
		shexport.count = shexport.cap;
		dictorderalpha(&shexport);
		dict_iter(&shexport, d_iterprint);
		free(shexport.env);
		return (1);
	}


	return (1);
}

/*
int	dodictorder(t_dict *dict, t_dict **least, size_t i)
{
	if (strcmp((*least)->key, dict->key) > 0) // least is bigger than dict
	{
		*least = dict;
	}
	(void)i;
	return (1);
}


t_dict	*shexport_init(t_dict *shenv)
{
	t_dict	*shexport;

	// Shalllow copy of shenv
	shexport = dict_new(shenv->key, shenv->value);
	shenv = shenv->next;
	while (shenv)
	{
		dict_add(shexport, shenv->key, shenv->value);
		shenv = shenv->next;
	}
	// Order alphabetically
	shexport_orderalpha(&shexport);
	return (shexport);
}
*/