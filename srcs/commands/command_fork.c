/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:10:54 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/09 17:18:30 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	command_fork(t_command command, t_promptinfo *prompt)
{
	// printf("%s\n", command.args[1]);
	if (!ft_strcmp(command.program, "change"))
		change(command, prompt);
	else if (!ft_strcmp(command.program, "pwd"))
		// pwd_command();
		printworkdirec(prompt);
	else if (!ft_strcmp(command.program, "clear"))
		clear_command();
	else if (!ft_strcmp(command.program, "exit"))
		exit_command();
	else if (!ft_strcmp(command.program, "echo"))
		echo(&command);
	else if (! ft_strcmp(command.program, "cd"))
		cd(&command, prompt);
	else if (! ft_strcmp(command.program, "env"))
		shenvprint(prompt, envstyle);
	else if (! ft_strcmp(command.program, "export"))
		shenvprint(prompt, exportstyle);
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
