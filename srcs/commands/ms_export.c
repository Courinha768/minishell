/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:16:24 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/20 13:42:14 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

/* Gives pos where the char is
 * Not idx! 0 is not-found: 1 is first ([0])
 * 2 is second ([1]) ...
*/
size_t	strichr(const char *s, int c)
{
	size_t	i;

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

	j = 0;
	while (j < dict->count)
	{
		min = &dict->env[j];
		i = j + 1;
		while (i < dict->count)
		{
			if (antstrcmp(*min, dict->env[i]) > 0)
				ft_strswap(min, &(dict->env[i]));
			i++;
		}
		j++;
	}
}

void	d_itexprtprint(char *keyval)
{
	size_t	i;

	if (!keyval)
		return ;
	printf("declare -x ");
	if (ft_strchr(keyval, '=') == NULL)
	{
		printf("%s\n", keyval);
		return ;
	}
	i = 0;
	while (keyval[i] != '\0')
	{
		printf("%c", keyval[i]);
		if (keyval[i] == '=')
		{
			printf("\"%s\"\n", &keyval[i + 1]);
			break ;
		}
		i++;
	}
}

void	export_print(t_command *command, t_promptinfo *prompt)
{
	t_dict	*dict;
	t_dict	shexport;

	(void)command;
	dict = &prompt->newenv;
	shexport.env = malloc(sizeof(char *) * dict->count);
	ft_memcpy(shexport.env, dict->env, dict->count * sizeof(char *));
	shexport.cap = dict->count;
	shexport.count = shexport.cap;
	dictorderalpha(&shexport);
	dict_iter(&shexport, d_itexprtprint);
	free(shexport.env);
}

/**
 * Export
*/
void	ms_export(t_command *command, t_promptinfo *prompt)
{
	size_t	len;
	size_t	i;

	len = ft_mtrxlen((void **)command->args);
	if (len <= 1)
		return (exe_fuc(command, prompt, export_print));
	i = 1;
	while (i < len)
	{
		dict_add(&prompt->newenv, ft_strdup(command->args[i]));
		i++;
	}
}
