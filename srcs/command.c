/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:10:54 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/05 13:10:56 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	check_command(t_command command, t_prompt *prompt)
{
	if (!ft_strcmp(command.command, "change"))
		change(command, prompt);
	else if (!ft_strcmp(command.command, "pwd"))
		printf("%s\n", getenv("PWD"));
	else if (!ft_strcmp(command.command, "clear"))
		clear_shell();
	else if (!ft_strcmp(command.command, "exit"))
	{
		free_everything(prompt, &command);
		kill(getppid(), SIGKILL);
	}
	else
		printf("%s: command not found\n", command.command);
}
