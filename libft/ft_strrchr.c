/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:20:20 by aappleto          #+#    #+#             */
/*   Updated: 2021/10/22 18:26:06 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	a;

	i = 0;
	a = c;
	while (s[i])
		i++;
	if (!a)
		return ((char *)(&(s[i])));
	while (s[i] != a && i > -1)
		i--;
	if (i == -1)
		return (NULL);
	else
		return ((char *)(&(s[i])));
}
