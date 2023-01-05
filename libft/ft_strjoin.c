/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:37:32 by aappleto          #+#    #+#             */
/*   Updated: 2021/10/22 13:03:38 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	counter1;
	unsigned int	counter2;
	char			*join;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	counter1 = 0;
	counter2 = 0;
	while (s1[counter1])
	{
		join[counter1] = s1[counter1];
		counter1++;
	}
	while (s2[counter2])
		join[counter1++] = s2[counter2++];
	join[counter1] = '\0';
	return (join);
}
/*
int	main(int ac, char **av)
{
	ac = 0;
	printf("%s", ft_strjoin(av[1], av[2]));
}*/
