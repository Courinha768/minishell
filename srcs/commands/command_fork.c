/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:10:54 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/09 18:07:01 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	command_fork(t_command *command, int i, t_promptinfo *prompt)
{
	if (!ft_strcmp(command[i].program, "change"))
		change(command[i], prompt);
	else if (!ft_strcmp(command[i].program, "echo"))
		echo(command, i);
	else if (! ft_strcmp(command[i].program, "cd"))
		cd(&(command[i]), prompt);
	else if (!ft_strcmp(command[i].program, "pwd"))
		pwd_command(prompt, command, i);
	else if (!ft_strcmp(command[i].program, "clear"))
		clear_command();
	else if (!ft_strcmp(command[i].program, "exit"))
		exit_command();
		cd(&command, prompt);
	else if (! ft_strcmp(command.program, "env"))
		shenvprint(prompt, envstyle);
	else if (! ft_strcmp(command.program, "export"))
		shenvprint(prompt, exportstyle);
	else
		printf("%s: command not found\n", command[i].program);
}

void	read_commands(t_command *commands, t_promptinfo *prompt)
{
	int	i;

	i = -1;
	while (commands[++i].program)
		command_fork(commands, i, prompt);
	//print_commands(commands);
	free_commands(commands);
}
