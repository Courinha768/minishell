/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:10:54 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/12 23:55:49 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	command_fork(t_command *commands, int i, t_promptinfo *prompt)
{
	if (!ft_strcmp(commands[i].program, "change"))
		change(commands[i], prompt);
	else if (!ft_strcmp(commands[i].program, "echo"))
		echo(commands[i]);
	else if (! ft_strcmp(commands[i].program, "cd"))
		cd(&(commands[i]), prompt);
	else if (!ft_strcmp(commands[i].program, "pwd"))
		pwd_command(prompt, commands[i]);
	else if (!ft_strcmp(commands[i].program, "clear"))
		clear_command();
	else if (!ft_strcmp(commands[i].program, "exit"))
		exit_command();
	else if (! ft_strcmp(commands[i].program, "env"))
		dictprint(prompt->shenv, envstyle);
	else if (! ft_strcmp(commands[i].program, "export"))
		func_export(commands[i], prompt);
	//else if (! ft_strncmp(commands[i].program, "/bin", 4))
	//{
	//	int pid = fork();
	//	if (!pid)
	//	{
	//		execve(commands[i].program, commands[i].args, (char *const *)getenv("ENV"));
	//		exit(1);
	//	}
	//}
	else
		printf("%s: command not found\n", commands[i].program);
}

void	read_commands(t_command *commands, t_promptinfo *prompt)
{
	int	i;

	i = -1;
	while (commands[++i].program)
		command_fork(commands, i, prompt);
	print_commands(commands);
	free_commands(commands);
}