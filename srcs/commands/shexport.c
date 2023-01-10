/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shexport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:16:24 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/10 09:29:58 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	shexport_orderalpha(t_dict **shenv)
{
	
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
	shexport_orderalpha(&shenv);
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