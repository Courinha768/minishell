/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:31:36 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/10 20:31:38 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	pwd_command(t_promptinfo *prompt, t_command *commands, int i)
{
	printf("%s\n", prompt->pwd);
	if (commands[i].pipe_flag == 5)
		write_into_file(prompt->pwd, commands[i].args[2]);
	if (commands[i + 1].pipe_flag == 1)
		commands[i + 1].output = ft_strdup(prompt->pwd);
}
