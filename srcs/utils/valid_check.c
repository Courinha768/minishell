/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:25:36 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/17 19:29:00 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	is_valid(char c)
{
	if (!c)
		return (0);
	else if (c == '|')
		return (0);
	return (1);
}

int	is_valid2(char c)
{
	if (!c)
		return (0);
	else if (c == '|' || c == '>' || c == '<')
		return (0);
	return (1);
}

int	rl_is_valid(char c)
{
	return (c != '|' && c != '>' && c != '<' && c != '&');
}

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
