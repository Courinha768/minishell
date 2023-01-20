/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:16:15 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/20 00:14:33 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	ms_echo(t_command *command, t_promptinfo *prompt)
{
	int		printlnb;
	size_t	i;

	(void)prompt;
	printlnb = 1;
	i = 1;
	if (command->args[1] && ! strcmp(command->args[1], "-n"))
	{
		printlnb = 0;
		i++;
	}
	while (command->args[i] != NULL)
	{
		if (! ft_strcmp(command->args[i], "$?"))
		{
			ft_putnbr_fd(info()->errorkeep, 1);
		}
		ft_putstr_fd(command->args[i], 1);
		i++;
		if (command->args[i] != NULL)
			ft_putchar_fd(' ', 1);
	}
	if (printlnb)
		ft_putchar_fd('\n', 1);
}
