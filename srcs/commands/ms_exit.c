/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:30:57 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/20 13:41:13 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	ft_strisdigit(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (! ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ms_exit(t_command *command, t_promptinfo *prompt)
{
	(void)command;
	(void)prompt;
	printf("exit\n");
	if (ft_mtrxlen((void **)command->args) <= 1)
	{
		info()->finished = 1;
		return ;
	}
	else if (command->args[1] && ft_strisdigit(command->args[1]))
	{
		info()->errorkeep = ft_atoi(command->args[1]);
		if (command->args[2])
		{
			info()->errorkeep = 1;
			return ((void)printf("minishell: exit: too many arguments\n"));
		}
	}
	else
	{
		info()->errorkeep = 2;
		printf("minishell: exit: %s: numeric argument required\n",
			command->args[1]);
	}	
	info()->finished = 1;
}
