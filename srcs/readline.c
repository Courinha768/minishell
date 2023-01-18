/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:24:27 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/18 16:21:30 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

t_command	createcommand(char **tokens)
{
	t_command	command;
	static int	s_token;
	int			i;

	if (!s_token)
		s_token = 0;
	command.fdin = 0;
	command.fdout = 1;
	command.pid = 0;
	if (s_token)
		s_token++;
	command.program = ft_strdup(tokens[s_token]);
	command.args = (char **)malloc(sizeof(char *)
			* (countargs(tokens, s_token) + 1));
	if (!command.args)
		return (nullcommand());
	i = 0;
	while (tokens[s_token] && rl_is_valid(tokens[s_token][0]))
		command.args[i++] = ft_strdup(tokens[s_token++]);
	command.args[i] = NULL;
	handle_redd(&command, tokens, &s_token);
	if (!tokens[s_token])
		s_token = 0;
	return (command);
}

char	*read_line(t_promptinfo *promptinfo)
{
	char		*prompt;
	char		*line;

	prompt = create_prompt(promptinfo);
	line = readline(prompt);
	free(prompt);
	if (!line)
	{
		return (line);
	}
	if (!line[0])
	{
		return (line);
	}
	add_history(line);
	return (line);
}

void	free_tokens(char **tokens)
{
	int	i;

	i = -1;
	while (tokens[++i])
		free(tokens[i]);
	free(tokens);
}

t_command	*create_commands(char *line, t_dict *env)
{
	int			nbr_of_commands;
	int			i;
	char		**tokens;
	t_command	*commands;

	if (!line || !line[0])
		return (NULL);
	tokens = ms_split(ft_strdup(line)); //Alert: allocation
	if (!line_valid(tokens))
	{
		printf("line not valid\n");
		return (NULL);
	}
	(void)env;
	nbr_of_commands = countcommands(line);
	commands = malloc(sizeof(t_command) * (nbr_of_commands + 1));
	if (!commands)
		return (NULL);
	i = 0;
	while (nbr_of_commands--)
		commands[i++] = createcommand(tokens);
	commands[i] = nullcommand();
	//print_commands(commands);
	strip_quotes(commands, env);
	free_tokens(tokens);
	return (commands);
}
