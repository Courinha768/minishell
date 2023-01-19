/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_readline_utils4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:03:02 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/19 17:12:07 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/include.h"

int	nbr_of_struct_tokens(char **split)
{
	int	i;
	int	size;

	i = -1;
	size = 1;
	while (split[++i])
	{
		if (split[i][0] == PIPE)
			size++;
	}
	return (size);
}

static int	find_stopper_split(char **split, int i)
{
	i++;
	while (split[i] && split[i][0] != PIPE)
		i++;
	return (i);
}

t_tokens	create_token_struct(char **split)
{
	static int	i;
	t_tokens	token;
	int			j;

	if (!i)
		i = 0;
	i -= 1;
	reset_all_flags(&token);
	if (i > -1 && split[i][0] == PIPE)
		change_pipe_flags(&token, PIPE_BEHIND);
	token.tokens = malloc(sizeof(char *) * (find_stopper_split(split, i) + 1));
	if (!token.tokens)
		return (null_token_struct());
	j = 0;
	while (split[++i] && split[i][0] != PIPE)
		token.tokens[j++] = ft_strdup(split[i]);
	token.tokens[j] = NULL;
	if (split[i] && split[i][0] == PIPE)
		change_pipe_flags(&token, PIPE_AHEAD);
	if (!split[i])
		i = 0;
	else
		i++;
	return (token);
}

t_tokens	null_token_struct(void)
{
	t_tokens	token;

	reset_all_flags(&token);
	token.tokens = NULL;
	//free(token.redd.file);
	token.redd.file = 0;
	return (token);
}