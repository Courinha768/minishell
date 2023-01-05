/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:06:02 by aappleto          #+#    #+#             */
/*   Updated: 2021/10/25 16:01:35 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_invert(char *nbr, int i, int t)
{
	int		j;
	char	a;

	j = t;
	while (i > j)
	{
		a = nbr[i];
		nbr[i--] = nbr[j];
		nbr[j++] = a;
	}
}

char	*negative(int n)
{
	int		i;
	int		n2;
	char	*nbr;

	n *= -1;
	n2 = n;
	i = 0;
	while (n2 > 0)
	{
		n2 = n2 / 10;
		i++;
	}
	nbr = (char *)malloc(sizeof(char) * (i + 2));
	if (!nbr)
		return (NULL);
	nbr[0] = '-';
	i = 1;
	while (n > 0)
	{
		nbr[i++] = (n % 10) + 48;
		n = n / 10;
	}
	nbr[i--] = 0;
	ft_invert(nbr, i, 1);
	return (nbr);
}

char	*idk(int n)
{
	char	*nbr;
	char	*why;
	int		i;

	n = 0;
	i = -1;
	why = "-2147483648";
	nbr = (char *)malloc(12);
	if (nbr == NULL)
		return (NULL);
	while (why[++i])
		nbr[i] = why[i];
	nbr[i] = 0;
	return (nbr);
}

char	*path(int n)
{
	char	*nbr;

	if (n == 0)
	{
		nbr = (char *)malloc(2);
		if (nbr == NULL)
			return (NULL);
		nbr[0] = 48;
		nbr[1] = 0;
		return (nbr);
	}
	if (n == -2147483648)
		return (idk(n));
	if (n < 0)
		return (negative(n));
	return (0);
}

char	*ft_itoa(int n)
{
	int		i;
	int		n2;
	char	*nbr;

	if (n == 0 || n == -2147483648 || n < 0)
		return (path(n));
	i = 0;
	n2 = n;
	while (n2 > 0)
	{
		n2 = n2 / 10;
		i++;
	}
	nbr = (char *)malloc(sizeof(char) * (i + 1));
	if (!nbr)
		return (NULL);
	i = 0;
	while (n > 0)
	{
		nbr[i++] = (n % 10) + 48;
		n = n / 10;
	}
	nbr[i--] = 0;
	ft_invert(nbr, i, 0);
	return (nbr);
}
/*
static void		ft_print_result(char *s)
{
	int		len;

	if (!s)
		write(1, "NULL", 4);
	else
	{
		len = 0;
		while (s[len])
			len++;
		write(1, s, len);
		free(s);
	}
}

int	main(void)
{
	ft_print_result(ft_itoa(-2147483648));
}*/
