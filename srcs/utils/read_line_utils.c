/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:25:39 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/08 17:55:05 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	args_counter(void)
{
	int	i;

	i = token()->current_token;
	while (is_valid(token()->token[i][0]))
		i++;
	return (i);
}

int	count_commands(char *line)
{
	int	i;
	int	counter;

	i = -1;
	counter = 0;
	while (line[++i])
	{
		if (line[i] == 124 || line[i] == 62 || line[i] == 60)
		{
			counter++;
			if (line[i + 1] == 62 || line[i + 1] == 60)
				i++;
		}
	}
	return (counter + 1);
}
