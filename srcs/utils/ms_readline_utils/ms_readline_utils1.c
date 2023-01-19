/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_readline_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:02:55 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/19 18:58:49 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/include.h"

void	reset_all_flags(t_tokens *token)
{
	token->pipe.pipe_ahead = FALSE;
	token->pipe.pipe_behind = FALSE;
	token->redd.red_i = FALSE;
	token->redd.red_o = FALSE;
	token->redd.red_d = FALSE;
	token->redd.red_a = FALSE;
	//token->redd.file = ft_strdup("nada");
}

void	change_pipe_flags(t_tokens *token, int flag_to_change)
{
	if (flag_to_change == PIPE_AHEAD)
		token->pipe.pipe_ahead = TRUE;
	else if (flag_to_change == PIPE_BEHIND)
		token->pipe.pipe_behind = TRUE;
}

void	change_redd_flags(t_tokens *token, int flag_to_change)
{
	if (flag_to_change == RED_I)
		token->redd.red_i = TRUE;
	else if (flag_to_change == RED_O)
		token->redd.red_o = TRUE;
	else if (flag_to_change == RED_D)
		token->redd.red_d = TRUE;
	else if (flag_to_change == RED_A)
		token->redd.red_a = TRUE;
}

void	add_redd_file(t_tokens *token, char *file)
{
	token->redd.file = ft_strdup(file);
}

int	is_redirection(char *token)
{
	if (!ft_strcmp(token, RED_IN))
		return (RED_I);
	else if (!ft_strcmp(token, RED_OUT))
		return (RED_O);
	else if (!ft_strcmp(token, RED_IDK))
		return (RED_D);
	else if (!ft_strcmp(token, RED_APP))
		return (RED_A);
	return (FALSE);
}

