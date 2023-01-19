/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_readline_utils3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:02:59 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/19 22:17:21 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/include.h"

int	is_stopers(char *s, int i)
{
	int	j;
	int	inside_quotes;
	int	inside_squotes;

	j = -1;
	if (s[i] != '|' && s[i] != '>' && s[i] != '>')
		return (FALSE);
	inside_quotes = -1;
	inside_squotes = -1;
	while (++j < i)
	{
		if (s[j] == '\"' && inside_squotes < 0)
			inside_quotes *= -1;
		else if (s[j] == '\'' && inside_quotes < 0)
			inside_squotes *= -1;
	}
	if (inside_quotes < 0 && inside_squotes < 0)
		return (TRUE);
	return (FALSE);
}

static int	find_stoper(char *str)
{
	int i;
	
	i = -1;
	while (str[++i])
		if (is_stopers(str, i))
			break;
	return (i);
}

char	**split_tokens(char *token_2_split)
{
	int		pipe_char;
	char	c[3];
	char	**splited_tokens;


	splited_tokens = malloc(sizeof(char *) * 4);
	if (!splited_tokens)
		return (NULL);
	pipe_char = find_stoper(token_2_split);
	c[0] = token_2_split[pipe_char];
	if (is_stopers(token_2_split, pipe_char + 1))
		c[1] = token_2_split[pipe_char + 1];
	else
		c[1] = 0;
	c[2] = 0;
	splited_tokens[0] = ft_strndup(token_2_split, 0, pipe_char);
	splited_tokens[1] = ft_strdup(c);
	if (is_stopers(token_2_split, pipe_char + 1))
		pipe_char++;
	splited_tokens[2] = ft_strndup(token_2_split, pipe_char + 1, END);
	splited_tokens[3] = NULL;
	free(token_2_split);
	return (splited_tokens);
}

int	need_2_split(char *str)
{
	int	i;
	int	valid;

	i = -1;
	valid = FALSE;
	while (str[++i])
	{
		if (isalnum(str[i]))
			valid = TRUE;
		if (is_stopers(str, i) && valid)
			return (TRUE);
	}
	return (FALSE);
}
