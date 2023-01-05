/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 12:31:41 by aappleto          #+#    #+#             */
/*   Updated: 2021/10/22 19:41:54 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int				a;
	unsigned int	i;
	unsigned int	nb;

	nb = 0;
	i = 0;
	a = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			a = 1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (a)
		nb = -nb;
	return ((int)nb);
}
/*
int	main(int ac, char **av)
{
	ac = 0;
	printf("%d\n", atoi(av[1]));
	printf("%d\n", ft_atoi(av[1]));
}*/
