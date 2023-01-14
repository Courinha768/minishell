/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strip_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:23:13 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/14 18:24:30 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	quote_is_valid(char const c, char breaker)
{
	static int	inside_quote;
	static int	inside_squote;

	if (c == '\"')
	{
		if (!inside_quote)
			inside_quote = 1;
		else
			inside_quote = 0;
	}
	else if (c == '\'')
	{
		if (!inside_squote)
			inside_quote = 1;
		else
			inside_squote = 0;
	}
	else if (c == breaker && !inside_quote && !inside_squote)
		return (0);
	return (1);
}

void	remove_quote(char *token, int i)
{
	while (token[++i])
		token[i - 1] = token[i];
	token[i - 1] = 0;
}

void	strip_quotes(char **tokens)
{
	int	i;
	int	j;
	int	inside_quote;
	int	inside_squote;

	i = -1;
	inside_quote = 0;
	inside_squote = 0;
	while (tokens[++i])
	{
		j = -1;
		while (tokens[i][++j])
		{
			if (tokens[i][j] == '\"' && !inside_squote)
			{
				remove_quote(tokens[i], j);
				if (!inside_quote)
					inside_quote = 1;
				else
					inside_quote = 0;
			}
			else if (tokens[i][j] == '\'' && !inside_quote)
			{
				remove_quote(tokens[i], j);
				if (!inside_quote)
					inside_squote = 1;
				else
					inside_squote = 0;
			}
		}
	}
}
