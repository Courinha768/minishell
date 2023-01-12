/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:25:36 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/12 19:31:57 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	is_valid(char c)
{
	if (!c)
		return (0);
	else if (c == 124)
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
