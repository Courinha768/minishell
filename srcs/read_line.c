/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:06:02 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/08 18:49:12 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	create_token(char *line)
{
	int	j;
	int	k;
	int	flag;

	j = 0;
	k = 0;
	flag = 0;
	while (line && *line)
	{
		if ((*line == 34 || *line == 39) && !flag)
			flag = *line;
		else if ((*line == 34 || *line == 39) && *line == flag)
			flag = 0;
		if (*line != ' ' || flag)
			token()->token[j][k++] = *line++;
		else if (!flag)
		{
			j++;
			k = 0;
			while (*line == 32)
				line++;
		}
		token()->token[j][k] = 0;
		token()->token[j + 1][0] = 0;
	}
}

t_command	create_commands(void)
{
	t_command	command;
	int			j;

	command.program = ft_strdup(token()->token[token()->current_token]);
	j = 0;
	command.args = (char **)malloc(sizeof(char *) * (args_counter() + 1));
	if (!command.args)
	{
		command.program = NULL;
		command.args = NULL;
		return (command);
	}
	while (is_valid(token()->token[token()->current_token][0]))
	{
		command.args[j] = ft_strdup(token()->token[token()->current_token]);
		j++;
		token()->current_token++;
	}
	command.args[j] = NULL;
	token()->current_token++;
	return (command);
}

t_command	*read_line(char *prompt)
{
	char		*line;
	t_command	*commands;
	int			nbr_of_commands;
	int			i;

	line = readline(prompt);
	free(prompt);
	create_token(line);
	nbr_of_commands = count_commands(line);
	commands = malloc(sizeof(t_command) * (nbr_of_commands + 1));
	if (!commands)
		return (NULL);
	i = 0;
	while (nbr_of_commands--)
		commands[i++] = create_commands();
	commands[i].program = NULL;
	commands[i].args = NULL;
	info()->line = line;
	return (commands);
}
