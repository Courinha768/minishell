/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_readline_utils3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:02:59 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/19 19:41:40 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/include.h"

int	is_stopers(char c)
{
	return (c == PIPE || c == CRED_IN || c == CRED_OUT);
	//take care of >> and <<
}

static int	find_stoper(char *str)
{
	int i;
	
	i = -1;
	while (str[++i])
		if (is_stopers(str[i]))
			break;
	return (i);
}

char	**split_tokens(char *token_2_split)
{
//	int		i;
	int		pipe_char;
	char	c[2];
	char	**splited_tokens;


	splited_tokens = malloc(sizeof(char *) * 4);
	if (!splited_tokens)
		return (NULL);
//	i = -1;
	pipe_char = find_stoper(token_2_split);
	c[0] = token_2_split[pipe_char];
	c[1] = 0;
	splited_tokens[0] = ft_strndup(token_2_split, 0, pipe_char);
	splited_tokens[1] = ft_strdup(c);
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
		if (is_stopers(str[i]) && valid)
			return (TRUE);
	}
	return (FALSE);
}
