/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:06:02 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/08 19:50:34 by aappleto         ###   ########.fr       */
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
	if (info()->line)
		free(info()->line);
	info()->line = line;
	return (commands);
}
