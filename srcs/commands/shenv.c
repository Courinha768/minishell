/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shenv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:25:14 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/11 18:19:44 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

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

t_dict	*shenv_init(t_promptinfo *prompt)
{
	t_dict	*head;

	//Alert: Allocation
	// head = dict_new(ft_strdup("SHELL"), ft_strjoin(prompt->pwd, "/minishell"));
	head = dict_new();
	
	// dict_add(head, ft_strdup("SHELL"), ft_strjoin(prompt->pwd, "/minishell"));
	dict_add(head, ft_strdup("PWD"), ft_strdup(getenv("PWD")));
	dict_add(head, ft_strdup("PATH"), ft_strdup(getenv("PATH")));
	dict_add(head, ft_strdup("HOME"), ft_strdup(getenv("HOME")));
	dict_add(head, ft_strdup("USER"), ft_strdup(getenv("USER")));
	return (head);
}
