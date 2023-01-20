/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:25:14 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/20 13:40:37 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

char	*strix(char *str, size_t q)
{
	return (&str[q]);
}

t_dict	shenv_init(char **envp)
{
	int		mtrxlen;
	t_dict	newenv;
	int		i;
	char	*tmp;

	mtrxlen = (int)ft_mtrxlen((void **)envp);
	newenv = dict_new(mtrxlen);
	i = 0;
	while (i < mtrxlen)
	{
		dict_add(&newenv, ft_strdup(envp[i]));
		i++;
	}
	tmp = ft_itoa(ft_atoi(dict_get(&newenv, "SHLVL")) + 1);
	dict_add(&newenv, ft_strjoin("SHLVL=", tmp));
	free(tmp);
	return (newenv);
}

void	d_envprint(char *keyval)
{
	if (keyval)
	{
		if (ft_strchr(keyval, '=') != NULL)
		{
			if (strix(ft_strchr(keyval, '='), 1) != NULL)
				printf("%s\n", keyval);
		}
	}
	(void)keyval;
}

void	ms_env(t_command *command, t_promptinfo *prompt)
{
	(void)command;
	dict_iter(&prompt->newenv, d_envprint);
}
