/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:15:55 by aappleto          #+#    #+#             */
/*   Updated: 2021/10/22 18:22:08 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;
	int		i;

	a = c;
	i = -1;
	while (s[++i])
		if (s[i] == a)
			return ((char *)(&(s[i])));
	if (s[i] == a)
		return ((char *)(&(s[i])));
	return (NULL);
}
