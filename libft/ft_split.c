/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ft_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:44:54 by aappleto          #+#    #+#             */
/*   Updated: 2021/10/25 18:44:56 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	segmentlen(char const *s, char c, int index)
{
	int	counter;

	counter = 0;
	while (s[index] != c && s[index])
	{
		counter++;
		index++;
	}
	return (counter);
}

int	sstrlen(char const *s, char c)
{
	int	a;
	int	index;
	int	counter;

	index = 0;
	a = 0;
	counter = 0;
	while (s[index])
	{
		if (s[index] != c)
		{
			counter++;
			a = 1;
			if (!s[index + 1])
				counter++;
		}
		if (s[index] == c && a)
		{
			counter++;
			a = 0;
		}
		index++;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	int		split_index;
	int		split_index2;
	char	**split;

	split = (char **)malloc(sizeof(char *) * sstrlen(s, c) + 1);
	if (!split)
		return (NULL);
	index = -1;
	split_index = 0;
	while (++index < (int)ft_strlen(s) && s[index])
	{
		split_index2 = 0;
		if (s[index] != c)
		{
			split[split_index] = (char *)malloc(segmentlen(s, c, index) + 1);
			if (!split[split_index])
				return (NULL);
			while (s[index] != c && s[index])
				split[split_index][split_index2++] = s[index++];
			split[split_index++][split_index2] = 0;
		}
	}	
	split[split_index] = NULL;
	return (split);
}

// int	main(int ac, char **av)
// {
// 	char	**split;
// 	int		i;

// 	ac = 0;
// 	i = 0;
// 	av[0] = 0;
// 	split = ft_split("  tripouille  42", ' ');
// 	while (split[i])
// 	{
// 		// printf("[%d]", i);
// 		printf("%s\n", split[i]);
// 		i++;
// 	}
// }
