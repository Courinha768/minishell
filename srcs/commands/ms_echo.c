/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:16:15 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/16 23:51:36 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	ms_echo(t_promptinfo *prompt, t_command *command)
{
	int		printlnb;
	size_t	i;

	(void)prompt;
	printlnb = 1;
	i = 1;
	if (! strcmp(command->args[1], "-n"))
	{
		printlnb = 0;
		i++;
	}
	while (command->args[i] != NULL)
	{
		ft_putstr_fd(command->args[i], 1);
		i++;
		if (command->args[i] != NULL)
			ft_putchar_fd(' ', 1);
	}
	if (printlnb)
		ft_putchar_fd('\n', 1);
}
