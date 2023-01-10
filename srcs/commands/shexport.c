/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shexport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:16:24 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/10 15:50:53 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	dodictorder(t_dict *dict, t_dict **least, size_t i)
{
	if (strcmp((*least)->key, dict->key) > 0) // least is bigger than dict
	{
		*least = dict;
	}
	(void)i;
	return (1);
}

void	shexport_orderalpha(t_dict **shexport)
{
	t_dict	*tmp;
	size_t	minidx;
	size_t	i;

	i = 0;
	while (i < dictsize(*shexport) / 2 + 1)
	{
		minidx = i + dictkeymin(dictget_it(*shexport, i));
		if (minidx <= 0)
			break ;

		tmp = dict_pop(shexport, minidx);

		dict_insert(shexport, i, tmp);

		i++;
	}
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

int	func_export(t_command command, t_promptinfo *prompt)
{
	if (ft_mtrxlen((void **)command.args) < 2) // fine tune
	{
		dictprint(prompt->shexport, exportstyle);
		return (1);
	}
	printf("var-create mode\n");
	return (1);
}