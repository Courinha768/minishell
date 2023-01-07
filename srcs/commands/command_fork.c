/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:10:54 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/07 20:05:34 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	is_valid(void)
{
	char	c;
	char	d;

	c = info()->token[info()->current_token][0];
	d = info()->token[info()->current_token][1];
	if (c == 124 || c == 60 || c == 62)
		return (0);
	if (!d)
		return (1);
	if ((c == 60 && d == 60) || (c == 62 && d == 62))
		return (0);
	return (1);
}

t_command	read_token(void)
{
	t_command	command;
	int			i;
	int			j;

	i = -1;
	while (info()->token[info()->current_token][++i])
		command.program[i] = info()->token[info()->current_token][i];
	command.program[i] = 0;
	j = 0;
	while (is_valid() && info()->token[info()->current_token][0])
	{
		i = -1;
		while (info()->token[info()->current_token][++i])
			command.args[j][i] = info()->token[info()->current_token][i];
		command.args[j][i] = 0;
		j++;
		info()->current_token++;
	}
	if (info()->token[info()->current_token][0] == 124)
		info()->current_token++;
	return (command);
}

void	check_command(t_promptinfo *prompt)
{
	t_command	command;

	command = read_token();
	if (!ft_strcmp(command.program, "change"))
		change(command, prompt);
	else if (!ft_strcmp(command.program, "pwd"))
		printf("%s\n", getenv("PWD"));
	else if (!ft_strcmp(command.program, "clear"))
		clear_shell();
	else if (!ft_strcmp(command.program, "exit"))
		info()->finnished = 1;
	else
		printf("%s: command not found\n", command.program);
}
