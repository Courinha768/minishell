/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_readline_utils9.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:37:53 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/20 13:39:30 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/include.h"

static void	replace_1(char **token, t_dict *env)
{
	int		dollar_sign;
	char	key[1024];
	int		i;
	char	*temp;

	dollar_sign = ms_strnstr(*token, "$", -1);
	i = 0;
	if ((*token)[dollar_sign + 1] == '?')
		key[i++] = '?';
	else
		while (ft_isalnum((*token)[++dollar_sign]))
			key[i++] = (*token)[dollar_sign];
	key[i] = 0;
	if (!ft_strcmp(key, "?\0"))
	{
		temp = ft_itoa(info()->errorkeep);
		replace_key(token, key, temp);
		free(temp);
	}
	else
		replace_key(token, key, dict_get(env, key));
}

void	place_evars(t_command **commands, t_dict *env)
{
	int	i;
	int	j;
	int	a;

	i = -1;
	while ((*commands)[++i].program)
	{
		j = -1;
		while ((*commands)[i].args[++j])
		{
			a = has_stopers((*commands)[i].args[j]);
			if (a == 1)
				replace_1(&((*commands)[i].args[j]), env);
			else if (a == 2)
				replace_key(&((*commands)[i].args[j]), "~",
					dict_get(env, "HOME"));
			if (a)
				j--;
			a = 0;
		}
	}
	free((*commands)[0].program);
	(*commands)[0].program = ft_strdup((*commands)[0].args[0]);
}
