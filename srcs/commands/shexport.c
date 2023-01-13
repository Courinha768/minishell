/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shexport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:16:24 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/13 17:31:34 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

size_t	ft_min(size_t a, size_t b)
{
	if (b < a)
		return (b);
	return (a);
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
			return (i);
	}
	return (0);
}


void	dictorderalpha(t_dict *dict)
{
	size_t	j;
	size_t	i;
	char	*min;
	size_t	whr;

	min = dict->env[0];
	whr = strichr(min, '=');
	j = 1;
	while (j < dict->count / 2 + 1)
	{
		i = j;
		while (i < dict->count)
		{
			whr = ft_min(whr, strichr(dict->env[i], '='));
			if (strncmp(min, dict->env[i], whr) > 0)
				printf("DO SOMETHING!\n");
			i++;
		}
		j++;
	}
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

/**
 * Export with no options
*/
int	func_export(t_command command, t_promptinfo *prompt)
{
	t_dict	shexport;

	shexport.env = malloc(sizeof(char *) * prompt->shenv->count);
	ft_memcpy(shexport.env, prompt->shenv->env, prompt->shenv->count * sizeof(char *));
	shexport.cap = prompt->shenv->count;
	shexport.count = shexport.cap;
	dict_iter(&shexport, d_iterprint);
	free(shexport.env);
	(void)command;
	return (1);
}