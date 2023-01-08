/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:16:15 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/08 18:49:23 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

//missing norminette
void	echo(void)
{
	int	i;
	int	flag_1;
	int	flag_2;

	i = 4;
	flag_1 = 0;
	flag_2 = 0;
	if (info()->line[i + 1] == '-' && info()->line[i + 2] == 'n')
	{
		flag_1 = 1;
		i += 3;
	}
	while (is_valid(info()->line[++i]))
	{
		if ((info()->line[i] == 34 || info()->line[i] == 39) && !flag_2)
			flag_2 = info()->line[i];
		else if (info()->line[i] == 34 || info()->line[i] == 39)
			if (info()->line[i] == flag_2)
				flag_2 = -1;
		if (info()->line[i] == 34 || info()->line[i] == 39)
		{
			if (info()->line[i] != flag_2 && flag_2 != -1)
			{
				flag_2 = 0;
				ft_putchar_fd(info()->line[i], 1);
			}
		}
		else
			ft_putchar_fd(info()->line[i], 1);
	}
	if (!flag_1)
		printf("\n");
}
