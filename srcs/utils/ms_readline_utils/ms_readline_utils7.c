/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_readline_utils7.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 00:08:59 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/20 05:16:47 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/include.h"

t_command	nullcommand(void)
{
	t_command	null_command;

	null_command.program = NULL;
	null_command.args = NULL;
	null_command.pid = -1;
	null_command.fdin = 0;
	null_command.fdout = 1;
	return (null_command);
}

void	remove_char(char **str, int i)
{
	while ((*str)[++i])
		(*str)[i - 1] = (*str)[i];
	(*str)[i - 1] = 0;
}

void	remove_quotes_sub(char **str)
{
	int	i;
	int	inside_quotes;
	int	inside_squotes;

	i = -1;
	inside_quotes = -1;
	inside_squotes = -1;
	while ((*str)[++i])
	{
		if ((*str)[i] == '\"' && inside_squotes < 0)
		{
			remove_char(str, i);
			i--;
			inside_quotes *= -1;
		}
		else if ((*str)[i] == '\'' && inside_quotes < 0)
		{
			remove_char(str, i);
			i--;
			inside_squotes *= -1;
		}
	}
}

void	remove_quotes(t_command **commands)
{
	int	i;
	int	j;

	i = -1;
	while ((*commands)[++i].program)
	{
		j = -1;
		while ((*commands)[i].args[++j])
			remove_quotes_sub(&((*commands)[i].args[j]));
	}
}
