/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antstrcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:36:33 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/16 23:06:53 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	antstrcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 && !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* Gives pos where the strings diverge
 * Not idx! 0 is wrong: 1 is first ([0])
 * 2 is second ([1]) ...
*/
size_t	strcmpwhr(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 && !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (i + 1);
		i++;
	}
	return (i + 1);
}

/*
int main(void)
{
	char	word1[] = "helloBgoZ";
	char	word2[] = "helloBgoQ";
	int		size	= 9;
	printf("%d\n", strncmp(word1, word2, size));
	printf("%d\n", ft_strncmp(word1, word2, size));
	return 0;
}
*/