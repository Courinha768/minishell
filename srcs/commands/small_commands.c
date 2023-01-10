/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:55:27 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/10 18:06:23 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	pwd_command(t_promptinfo *prompt, t_command *commands, int i)
{
	printf("%s\n", prompt->pwd);
	if (commands[i + 1].pipe_flag)
		commands[i + 1].output = ft_strdup(prompt->pwd);
}

void	clear_command(void)
{
	clear_shell();
}

void	exit_command(void)
{
	info()->finished = 1;
}
