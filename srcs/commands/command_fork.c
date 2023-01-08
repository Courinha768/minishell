/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:10:54 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/08 17:24:10 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

// t_command	read_token(void)
// {
// 	t_command	command;
// 	int			i;
// 	int			j;

// 	i = -1;
// 	while (info()->token[info()->current_token][++i])
// 		command.program[i] = info()->token[info()->current_token][i];
// 	command.program[i] = 0;
// 	j = 0;
// 	while (is_valid() && info()->token[info()->current_token][0])
// 	{
// 		i = -1;
// 		while (info()->token[info()->current_token][++i])
// 			command.args[j][i] = info()->token[info()->current_token][i];
// 		command.args[j][i] = 0;
// 		j++;
// 		info()->current_token++;
// 	}
// 	command.args[j][0] = 0;
// 	command.args[j + 1][0] = 0;
// 	if (info()->token[info()->current_token][0] == 124)
// 		info()->current_token++;
// 	return (command);
// }

// void	command_fork(t_promptinfo *prompt)
// {
// 	t_command	command;

// 	command = read_token();
// 	if (!ft_strcmp(command.program, "change"))
// 		change(command, prompt);
// 	else if (!ft_strcmp(command.program, "pwd"))
// 		printf("%s\n", getenv("PWD"));
// 	else if (!ft_strcmp(command.program, "clear"))
// 		clear_shell();
// 	else if (!ft_strcmp(command.program, "exit"))
// 		return ;
// 	else if (!ft_strcmp(command.program, "echo"))
// 		echo();
// 	else
// 		printf("%s: command not found\n", command.program);
// }
