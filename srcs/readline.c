/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:24:27 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/17 13:23:43 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	countcommands(char *line)
{
	int	i;
	int	counter;

	if (!line)
		return (0);
	i = -1;
	counter = 1;
	while (line[++i])
	{
		if (line[i] == '|')
			counter++;
		if (line[i] == '&')
		{
			counter++;
			i++;
		}
	}
	return (counter);
}

int	countargs(char **tokens, int i)
{
	int	counter;

	counter = 0;
	while (tokens[i] && rl_is_valid(tokens[i][0]))
	{
		counter++;
		i++;
	}
	return (counter);
}

t_command	nullcommand(void)
{
	t_command	command;

	command.args = NULL;
	command.program = NULL;
	command.fdin = 0;
	command.fdout = 0;
	return (command);
}

t_command	createcommand(char **tokens)
{
	t_command	command;
	static int	static_current_token;
	int			current_token;
	int			i;

	if (!static_current_token)
		static_current_token = 0;
	command.fdin = 0;
	command.fdout = 1;
	current_token = static_current_token;
	if (current_token)
		current_token++;
	command.program = ft_strdup(tokens[current_token]);
	command.args = (char **)malloc(sizeof(char *)
			* (countargs(tokens, current_token) + 1));
	if (!command.args)
		return (nullcommand());
	i = 0;
	while (tokens[current_token] && rl_is_valid(tokens[current_token][0]))
	{
		command.args[i++] = ft_strdup(tokens[current_token]);
		current_token++;
	}
	command.args[i] = NULL;
	handle_redd(&command, tokens, &current_token);
	static_current_token = current_token;
	if (!tokens[current_token])
		static_current_token = 0;
	return (command);
}

char	*read_line(char *prompt)
{
	char		*line;

	line = readline(prompt);
	free(prompt);
	if (!line)
	{
		return (NULL);
		// free_promptinfo()
		// exit(0);
	}
	if (!line[0])
		return (NULL);
	add_history(line);
	return (line);
}

t_command	*create_commands(char *line)
{
	int			nbr_of_commands;
	int			i;
	char		**tokens;
	t_command	*commands;

	if (!line[0])
		return (NULL);
	tokens = fancy_split(ft_strdup(line), ' '); //Alert: allocation
	if (!line_valid(tokens))
	{
		printf("line not valid\n");
		return (NULL);
	}
	strip_quotes(tokens);
	nbr_of_commands = countcommands(line);
	free(line);
	commands = malloc(sizeof(t_command) * (nbr_of_commands + 1));
	if (!commands)
		return (NULL);
	i = 0;
	while (nbr_of_commands--)
	{
		commands[i] = createcommand(tokens);
		i++;
	}
	commands[i] = nullcommand();
	i = -1;
	while (tokens[++i])
		free(tokens[i]);
	free(tokens);
	return (commands);
}
