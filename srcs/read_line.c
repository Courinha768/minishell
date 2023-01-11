/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:06:02 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/11 17:03:27 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

typedef struct s_antinorm2 {
	int	i;
	int	j;
	int	k;
	int	flag;
}	t_antinorm2;

void	create_token(char *line)
{
	t_antinorm2	fn;

	fn.j = 0;
	fn.k = 0;
	fn.i = 0;
	fn.flag = 0;
	while (line[fn.i] && line_valid(line[fn.i], line[fn.i + 1]))
	{
		if ((line[fn.i] == 34 || line[fn.i] == 39) && !fn.flag)
			fn.flag = line[fn.i];
		else if (line[fn.i] == 34 || line[fn.i] == 39)
			if (line[fn.i] == fn.flag)
				fn.flag = 0;
		if (line[fn.i] != 32 || fn.flag)
			token()->token[fn.j][fn.k++] = line[fn.i++];
		else if (!fn.flag)
		{
			fn.j++;
			fn.k = 0;
			while (line[fn.i] == 32)
				fn.i++;
		}
		token()->token[fn.j][fn.k] = 0;
		token()->token[fn.j + 1][0] = 0;
	}
}

t_command	create_commands(void)
{
	t_command	command;
	int			j;

	j = 0;
	command.pipe_flag = create_command_redirect_flag();
	command.args = (char **)malloc(sizeof(char *) * (args_counter() + 1));
	if (!command.args)
		return (null_command());
	command.program = ft_strdup(token()->token[token()->current_token]);
	while (is_valid(token()->token[token()->current_token][0]))
	{
		command.args[j] = ft_strdup(token()->token[token()->current_token]);
		j++;
		token()->current_token++;
	}
	command.args[j] = NULL;
	command.output = NULL;
	return (command);
}

void	strip_quotes(t_command *command)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = -1;
	while (command[++i].args)
	{
		j = -1;
		while (command[i].args[++j])
		{
			k = -1;
			while (command[i].args[j][++k])
			{
				if (command[i].args[j][k] == 34)
				{
					command[i].args[j][k] = 0;
					l = k;
					while (command[i].args[j][++l])
						command[i].args[j][l - 1] = command[i].args[j][l];
					command[i].args[j][l - 1] = 0;
				}
			}
		}
	}
}

void	create_flags(t_command *commands)
{
	int	i;
	int	j;

	i = -1;
	while (commands[++i].args)
	{
		j = -1;
		while (commands[i].args[++j])
		{
			if (commands[i].args[j][0] == '>')
			{
				if (commands[i].args[j][1] && commands[i].args[j][1] == '>')
					commands[i].pipe_flag = 5;
				else
					commands[i].pipe_flag = 3;
			}
			else if (commands[i].args[j][0] == '<')
			{
				if (commands[i].args[j][1] && commands[i].args[j][1] == '<')
					commands[i].pipe_flag = 4;
				else
					commands[i].pipe_flag = 2;
			}
		}
	}
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
	commands[i].pipe_flag = 0;
	if (info()->line)
		free(info()->line);
	info()->line = line;
	strip_quotes(commands);
	create_flags(commands);
	return (commands);
}
