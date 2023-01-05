/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:06:44 by aappleto          #+#    #+#             */
/*   Updated: 2021/10/22 21:52:39 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putnbr_fd (-21, fd);
			ft_putnbr_fd (47483648, fd);
			return ;
		}
		write(fd, "-", 1);
		n = n * -1;
	}
	if (n >= 0 && n < 10)
	{
		n = n + 48;
		write(fd, &n, 1);
	}
	else
	{
		ft_putnbr_fd (n / 10, fd);
		n = n % 10 + 48;
		write(fd, &n, 1);
	}
}
