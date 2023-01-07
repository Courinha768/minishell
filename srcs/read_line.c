/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:06:02 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/07 22:35:52 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	token(char *line)
{
	int	j;
	int	k;
	int	flag;

	j = 0;
	k = 0;
	flag = 0;
	while (line && *line)
	{
		if ((*line == 34 || *line == 39) && !flag)
			flag = *line;
		else if ((*line == 34 || *line == 39) && *line == flag)
			flag = 0;
		if (*line != ' ' || flag)
			info()->token[j][k++] = *line++;
		else if (!flag)
		{
			j++;
			k = 0;
			while (*line == 32)
				line++;
		}
		info()->token[j][k] = 0;
		info()->token[j + 1][0] = 0;
	}
}

void	read_line(char *prompt)
{
	char		*line;

	line = readline(prompt);
	free(prompt);
	token(line);
	info()->line = line;
}
