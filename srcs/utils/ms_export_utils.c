/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:32:19 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/17 19:33:35 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

size_t	ft_min(size_t a, size_t b)
{
	if (b < a)
		return (b);
	return (a);
}

size_t	ft_max(size_t a, size_t b)
{
	if (b > a)
		return (b);
	return (a);
}

void	ft_strswap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}
