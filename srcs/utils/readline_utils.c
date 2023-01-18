/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:52:27 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/17 22:15:32 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	countcommands(char *line)
{
	int	i;
	int	counter;
	int inside_quote;

	inside_quote = -1;
	if (!line)
		return (0);
	i = -1;
	counter = 1;
	while (line[++i])
	{
		if (line[i] == '\"' || line[i] == '\'')
			inside_quote *= -1;
		if (line[i] == '|' && inside_quote < 0)
			counter++;
		if (line[i] == '&' && inside_quote < 0)
		{
			counter++;
			i++;
		}
	}
	return (counter);
}

int	countargs(char **tokens, int i)
{
	int	counter;

	counter = 0;
	while (tokens[i] && rl_is_valid(tokens[i][0]))
	{
		counter++;
		i++;
	}
	return (counter);
}

t_command	nullcommand(void)
{
	t_command	command;

	command.args = NULL;
	command.program = NULL;
	command.fdin = 0;
	command.fdout = 0;
	return (command);
}