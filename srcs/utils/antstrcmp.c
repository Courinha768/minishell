/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antstrcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:36:33 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/10 14:16:01 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	antstrcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 && !s2)
		return (0);

	i = 0;
	while (! (s1[1] == '\0' || s2[i] == '\0'))
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
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