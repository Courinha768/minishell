/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:05:52 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/19 22:28:49 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

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
			inside_quotes *= -1;
		}
		else if ((*str)[i] == '\'' && inside_quotes < 0)
		{
			remove_char(str, i);
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

t_command	*create_commands(char *line, t_dict *env)
{
	char		**split;
	t_tokens	*tokens;
	t_command	*commands;
	int			i;

	(void)env;
	split = ms_split2(ft_strdup(line));
	tokens = create_tokens(split);
	check_for_redirection(&tokens);
	i = 0;
	while (tokens[i].tokens && tokens[i].tokens[0])
		i++;
	commands = malloc(sizeof(t_command) * (i + 1));
	if (!commands)
		return (NULL);
	i = -1;
	while (tokens[++i].tokens && tokens[i].tokens[0])
		commands[i] = create_command(&(tokens[i]));
	commands[i] = nullcommand();
	free(tokens);
	remove_quotes(&commands);
	return (commands);
}

char	*ms_readline(t_promptinfo *prompt_info)
{
	char	*prompt;
	char	*command_line;

	prompt = create_prompt(prompt_info);
	command_line = readline(prompt);
	free(prompt);
	if (!command_line || !command_line[0])
		return (command_line);
	add_history(command_line);
	return (command_line);
}