/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:30:21 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/12 19:36:11 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	line_valid(char **tokens)
{
	int	i;

	i = -1;
	while (tokens[++i])
	{
		if (!is_valid2(tokens[i][0]))
			if (tokens[i + 1] && !is_valid2(tokens[i + 1][0]))
				return (0);
	}
	return (1);
}