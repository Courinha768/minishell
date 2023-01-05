/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:11:21 by aappleto          #+#    #+#             */
/*   Updated: 2021/10/23 03:14:02 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	comp(char c, char const *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (0);
	return (1);
}

int	slen(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (!comp(s1[i], set))
		i++;
	j = (int)ft_strlen(s1);
	while (--j >= 0 && !comp(s1[j], set))
		i++;
	return (ft_strlen(s1) - i);
}

typedef struct s_stock
{
	int		i;
	int		j;
	int		k;
}	t_stock;

char	*ft_strtrim(char const *s1, char const *set)
{
	t_stock	v;
	char	*trim;

	v.i = -1;
	v.j = slen(s1, set);
	if (v.j <= 0)
	{
		trim = (char *)malloc(1);
		if (trim == NULL)
			return (NULL);
		trim[0] = '\0';
		return (trim);
	}
	trim = (char *)malloc(sizeof(char) * (v.j + 1));
	if (trim == NULL)
		return (NULL);
	v.i = 0;
	v.k = 0;
	while (!comp(s1[v.i], set))
		v.i++;
	v.j += v.i;
	while (v.i < v.j)
		trim[v.k++] = s1[v.i++];
	trim[v.k] = 0;
	return (trim);
}
/*
int main(void)
{
	char *trim = ft_strtrim("x   xxx   xxx", " x");
	printf("%s\n", trim);
	free (trim);
}*/
