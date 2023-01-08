/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:10:54 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/08 18:55:50 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	command_fork(t_command command, t_promptinfo *prompt)
{
	if (!ft_strcmp(command.program, "change"))
		change(command, prompt);
	else if (!ft_strcmp(command.program, "pwd"))
		pwd_command();
	else if (!ft_strcmp(command.program, "clear"))
		clear_command();
	else if (!ft_strcmp(command.program, "exit"))
		exit_command();
	else if (!ft_strcmp(command.program, "echo"))
		echo();
	else
		printf("%s: command not found\n", command.program);
}

void	read_commands(t_command *commands, t_promptinfo *prompt)
{
	int	i;

	i = -1;
	while (commands[++i].program)
		command_fork(commands[i], prompt);
	free_commands(commands);
}
