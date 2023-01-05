/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:18:19 by aappleto          #+#    #+#             */
/*   Updated: 2021/10/22 21:31:58 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*sub;

	i = 0;
	if (!len || !s || start > (unsigned int)ft_strlen(s))
	{
		sub = (char *)malloc(1);
		if (!sub)
			return (0);
		sub[0] = 0;
		return (sub);
	}
	if (!(len < ft_strlen(s)))
		len = ft_strlen(s);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	i--;
	while (++i < (int)len)
		sub[i] = s[i + start];
	sub[i] = 0;
	return (sub);
}

/*
int main(void)
{
	printf("%s", ft_substr("tripouille", 100, 1));
}*/
