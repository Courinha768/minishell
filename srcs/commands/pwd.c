/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:31:36 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/11 17:04:20 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	pwd_command(t_promptinfo *prompt, t_command *commands, int i)
{
	if (commands[i + 1].pipe_flag == 1)
		commands[i + 1].output = ft_strdup(prompt->pwd);
	else if (commands[i].pipe_flag == 3)
		overwrite_into_file(prompt->pwd, commands[i].args[2]);	
	else if (commands[i].pipe_flag == 5)
		write_into_file(prompt->pwd, commands[i].args[2]);
	else
		printf("%s\n", prompt->pwd);
}
