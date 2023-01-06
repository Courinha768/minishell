/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:10:54 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/06 20:18:30 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	check_command(t_command command, t_promptinfo *prompt)
{
	if (!ft_strcmp(command.program, "change"))
		change(command, prompt);
	else if (!ft_strcmp(command.program, "pwd"))
		printf("%s\n", getenv("PWD"));
	else if (!ft_strcmp(command.program, "clear"))
		clear_shell();
	// Not Working correctly
	// else if (!ft_strcmp(command.program, "exit"))
	// {
	// 	free_everything(prompt, &command);
	// 	kill(getppid(), SIGKILL);
	// }
	else
		printf("%s: command not found\n", command.program);
}
