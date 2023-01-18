/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:40:20 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/18 14:53:21 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	handle_redd(t_command *command, char **tokens, int *current_token)
{
	static int	fdin;
	int			p[2];

	if (fdin)
	{
		command->fdin = fdin;
		fdin = 0;
	}
	if (tokens[*current_token] && tokens[*current_token][0] == '>')
	{
		if (tokens[*current_token] && tokens[*current_token][1] == '>')
		{
			command->fdout = open(tokens[*current_token + 1], O_WRONLY
					| O_CREAT | O_APPEND, 0644);
		}
		else
			command->fdout = open(tokens[*current_token + 1], O_WRONLY
					| O_CREAT | O_TRUNC, 0644);
		*current_token += 2;
	}
	else if (tokens[*current_token] && tokens[*current_token][0] == '|')
	{
		if (pipe(p) < 0)
			return ;
		command->fdout = p[1];
		p[1] = 0;
		fdin = p[0];
	}
	else if (tokens[*current_token] && tokens[*current_token][0] == '<')
	{
		if (!access(tokens[*current_token + 1], F_OK))
			command->fdin = open(tokens[*current_token + 1], O_RDONLY , 0644);
		else
		{
			free(command->program);
			command->program = NULL;
			printf("minishell: no such file or directory: %s\n", tokens[*current_token + 1]);
		}
		*current_token += 2;
	}
}
