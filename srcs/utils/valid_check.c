/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:25:36 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/08 19:28:39 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	is_valid(char c)
{
	if (!c)
		return (0);
	else if (c == 124 || c == 60 || c == 62)
		return (0);
	return (1);
}

int	line_valid(char c, char d)
{
	if (!d)
		return (1);
	if (is_valid(c))
		return (1);
	if (c == '|' && d == '|')
		return (0);
	return (1);
}
