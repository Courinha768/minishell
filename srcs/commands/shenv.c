/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shenv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:25:14 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/16 17:21:31 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

/*
void	envstyle(t_dict *dict)
{
	//TODO: dont print if not value
	printf("%s=%s\n", dict->key, dict->value);
}

void	exportstyle(t_dict *dict)
{
	//TODO: order aplphabetically
	printf("declare -x %s=\"%s\"\n", dict->key, dict->value);
}

void	dictprint(t_dict *dict, void (*printstyle)(t_dict *))
{
	dict_iter(dict, printstyle);
}
*/

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
