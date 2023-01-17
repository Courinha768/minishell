/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shexport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:16:24 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/16 23:16:11 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

size_t	ft_min(size_t a, size_t b)
{
	if (b < a)
		return (b);
	return (a);
}

size_t	ft_max(size_t a, size_t b)
{
	if (b > a)
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
		while (i < dict->count)
		{
			whr = ft_min(whr, strichr(dict->env[i], '='));
			//TODO: use our strncmp
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

void	export_print(t_dict *dict)
{
	t_dict	shexport;
	
	// Only order-alpha and print
	shexport.env = malloc(sizeof(char *) * dict->count);
	ft_memcpy(shexport.env, dict->env, dict->count * sizeof(char *));
	shexport.cap = dict->count;
	shexport.count = shexport.cap;
	dictorderalpha(&shexport);
	dict_iter(&shexport, d_iterprint);
	free(shexport.env);
}

/**
 * Export
*/
void	ms_export(t_command *command, t_promptinfo *prompt)
{
	size_t	len;
	size_t	i;
	size_t	pos;

	len = ft_mtrxlen((void **)command->args);
	if (len <= 1)
		return (export_print(&prompt->newenv));
	i = 1;
	while (i < len)
	{
		pos = dict_pos(&prompt->newenv, command->args[i]);
		if (pos == 0)
			dict_add(&prompt->newenv, ft_strdup(command->args[i]));
		else
		{
			// In-situ replace
			if (strichr(command->args[i], '=') > 0)
			{
				free(prompt->newenv.env[pos - 1]);
				dict_insert(&prompt->newenv, pos -1, ft_strdup(command->args[i]));
			}
		}
		i++;
	}
}