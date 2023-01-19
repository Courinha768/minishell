/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:40:45 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/19 16:15:51 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	ms_unset(t_command *command, t_promptinfo *prompt)
{
	//TODO: unset a=s => `a=s': not a valid identifier
		// errno => 1
	size_t	i;
	size_t	pos;

	i = 0;
	while (++i < ft_mtrxlen((void **)command->args))
	{
		if (ft_strchr(command->args[i], '=') != NULL)
		{
			errno = EINVAL;
			perror(command->args[i]);
			continue ;
		}
		pos = dict_pos(&prompt->newenv, command->args[i]);
		if (pos != 0)
		{
			free(dict_pop(&prompt->newenv, command->args[i]));
		}
		// i++;
	}
}
