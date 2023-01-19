/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_readline_utils6.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:15:56 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/19 18:30:47 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/include.h"

t_tokens	*create_tokens(char **split)
{
	t_tokens	*tokens;
	int			nbr_of_structs;
	int			i;

	nbr_of_structs = nbr_of_struct_tokens(split);
	tokens = malloc(sizeof(t_tokens) * (nbr_of_structs + 1));
	if (!tokens)
		return (NULL);
	i = -1;
	while (++i < nbr_of_structs)
		tokens[i] = create_token_struct(split);
	tokens[i] = null_token_struct();
	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	return (tokens);
}

char	**ms_split2(char *line)
{
	char	**split;
	char	*token_2_split;
	int		i;

	split = ms_split(line);
	i = -1;
	while (split[++i])
	{
		if (need_2_split(split[i]))
		{
			token_2_split = remove_token(&split, i);
			add_multiple_tokens(&split, split_tokens(token_2_split), i);
		}
	}
	i = -1;
	return (split);
}

void	check_for_redirection(t_tokens **tokens)
{
	int	i;
	int	j;
	int	a;

	i = -1;
	while ((*tokens)[++i].tokens && (*tokens)[i].tokens[0])
	{
		j = -1;
		while ((*tokens)[i].tokens[++j])
		{
			a = is_redirection((*tokens)[i].tokens[j]);
			if (a)
			{
				change_redd_flags(&((*tokens)[i]), a);
				add_redd_file(&((*tokens)[i]), (*tokens)[i].tokens[j + 1]);
				free(remove_token(&((*tokens)[i].tokens), j + 1));
				free(remove_token(&((*tokens)[i].tokens), j));
			}
		}
	}
}

void	create_pipes_and_redirections(t_tokens *token, t_command *command)
{
	static int	fdin;
	int			p[2];
//	int			i;
	int			red_type;

//	i = -1;
	p[0] = 0;
	p[1] = 0;
	if (fdin)
	{
		command->fdin = fdin;
		fdin = 0;
	}
	red_type = find_redirection(*token);
	if (red_type)
	{
		create_redirection(*token, red_type, command);
	}
	if (token->pipe.pipe_ahead)
	{
		if (pipe(p) < 0)
			return ;
		command->fdout = p[1];
		fdin = p[0];
	}
}

char	**ft_strstrdup(char **tokens)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (tokens_len(tokens) + 1));
	if (!copy)
		return (NULL);
	i = -1;
	while (tokens[++i])
		copy[i] = ft_strdup(tokens[i]);
	copy[i] = NULL;
	return (copy);
}