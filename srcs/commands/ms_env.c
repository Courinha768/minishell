/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:25:14 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/17 09:31:15 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

char	*strix(char *str, size_t q)
{
	return (&str[q]);
}

t_dict	shenv_init(char **envp)
{
	t_dict	newenv;
	size_t	mtrxlen;
	size_t	i;
	
	(void)envp;
	(void)mtrxlen;
	(void)i;
	newenv = dict_new();
	mtrxlen = ft_mtrxlen((void **)envp);
	i = 0;
	while (i < mtrxlen)
	{
		newenv.env[i] = ft_strdup(envp[i]);
		i++;
	}
	newenv.cap = mtrxlen;
	newenv.count = i;
	return (newenv);
}

void	d_envprint(char *keyval)
{
	//TODO: print the keyval only if val exists
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

void	ms_env(t_dict *dict)
{
	dict_iter(dict, d_envprint);
}