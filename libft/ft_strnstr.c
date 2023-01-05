/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:35:14 by aappleto          #+#    #+#             */
/*   Updated: 2021/10/23 01:02:05 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <strings.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;

	i = 0;
	if (!needle[0])
		return ((char *)haystack);
	if ((int)len < 0)
		len = 4092;
	while (haystack[i] && i < (int)len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < (int)len)
		{
			if (!needle[j + 1])
				return (&(((char *)haystack)[i]));
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";

	printf("%s\n", strnstr(haystack, needle, -1));
	printf("%s\n", ft_strnstr(haystack, needle, -1));
}*/