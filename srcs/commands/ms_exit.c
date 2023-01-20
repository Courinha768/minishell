/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:30:57 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/20 06:32:37 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	ms_exit(t_command *command, t_promptinfo *prompt)
{
	int	i;

	//TODO:  add arguments
	(void)command;
	(void)prompt;
	i = -1;
	// mesmo que exitam 2 args que o 1 nao for numeros sai de qualquer maneira
	if (command->args[1])
	{
		while (command->args[1][++i])
		{
			if (!ft_isdigit(command->args[1][i]))
			{
				printf("minishell: exit: %s: numeric argument required",
					command->args[1]);
			}
		}
	}
	if (command->args[1] && command->args[2])
	{
		; // incorrect and shouldnt exit
	}
	info()->finished = 1;
	printf("exit\n");
}
