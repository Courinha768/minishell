/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:40:45 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/17 19:14:52 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	ms_unset(t_command *command, t_promptinfo *prompt)
{
	size_t	i;
	size_t	pos;

	i = 0;
	while (i < ft_mtrxlen((void **)command->args))
	{
		pos = dict_pos(&prompt->newenv, command->args[i]);
		if (pos != 0)
		{
			free(dict_pop(&prompt->newenv, command->args[i]));
		}
		i++;
	}
}
