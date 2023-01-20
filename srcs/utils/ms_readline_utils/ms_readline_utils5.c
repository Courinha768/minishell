/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_readline_utils5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:03:04 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/20 00:43:09 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/include.h"

int	find_redirection(t_tokens token)
{
	if (token.redd.red_i)
		return (RED_I);
	else if (token.redd.red_o)
		return (RED_O);
	else if (token.redd.red_d)
		return (RED_D);
	else if (token.redd.red_a)
		return (RED_A);
	return (FALSE);
}

void	create_red_d(t_tokens token, t_command *command)
{
	int		p[2];
	char	*line;

	pipe(p);
	command->fdin = p[0];
	line = ft_strdup("nada");
	while (1)
	{
		free(line);
		line = readline(">");
		if (!ft_strcmp(line, token.redd.file))
			break ;
		ft_putstr_fd(line, p[1]);
		ft_putstr_fd("\n", p[1]);
	}
	free(line);
	close(p[1]);
}

void	create_redirection(t_tokens token, int red_type, t_command *command)
{
	if (red_type == RED_I)
	{
		if (!access(token.redd.file, F_OK | R_OK))
			command->fdin = open(token.redd.file, O_RDONLY , 0644);
		//else
			//ERROR MSG
	}
	else if (red_type == RED_O)
	{
		command->fdout = open(token.redd.file, O_WRONLY
				| O_CREAT | O_TRUNC, 0644);
	}
	else if (red_type == RED_D)
	{
		create_red_d(token, command);
	}
	else if (red_type == RED_A)
	{
		command->fdout = open(token.redd.file, O_WRONLY
					| O_CREAT | O_APPEND, 0644);
	}
}

void	free_tokens(t_tokens *token)
{
	int	i;

	i = -1;
	while (token->tokens[++i])
		free(token->tokens[i]);
	free(token->tokens);
	if (token->redd.red_i || token->redd.red_o
			|| token->redd.red_d || token->redd.red_a)
		free(token->redd.file);
}

t_command	create_command(t_tokens	*token)
{
	t_command	command;

	command.fdin = 0;
	command.fdout = 1;
	command.args = ft_strstrdup(token->tokens);
	command.pid = -1;
	command.program = ft_strdup(token->tokens[0]);
	create_pipes_and_redirections(token, &command);
	free_tokens(token);
	return (command);
}

t_command	null_command(void)
{
	t_command command;

	command.args = NULL;
	command.program = NULL;
	command.fdin = 0;
	command.fdout = 1;
	command.pid = 0;
	return (command);
}