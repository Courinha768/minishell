/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:10:54 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/20 06:06:17 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	closefds(t_command *command)
{
	if (command->fdout != 1)
		close(command->fdout);
	if (command->fdin != 0)
		close(command->fdin);
}

void	exe_fuc(t_command *command, t_promptinfo *prompt, t_function fun)
{
	int	pid;

	pid = fork();
	if (!pid)
	{
		dup2(command->fdout, 1);
		dup2(command->fdin, 0);
		closefds(command);
		fun(command, prompt);
		free_promptinfo(prompt);
		free_commands(command);
		exit(1);
	}
	closefds(command);
	command->pid = pid;
}

static void	command_fork(t_command *command, t_promptinfo *prompt, t_dict *env)
{
	if (!ft_strcmp(command->program, "change"))
		change(*command, prompt);
	else if (!ft_strcmp(command->program, "echo"))
		exe_fuc(command, prompt, ms_echo);
	else if (! ft_strcmp(command->program, "cd"))
		ms_cd(command, prompt);
	else if (!ft_strcmp(command->program, "pwd"))
		exe_fuc(command, prompt, ms_pwd);
	else if (!ft_strcmp(command->program, "clear"))
		exe_fuc(command, prompt, ms_clear);
	else if (!ft_strcmp(command->program, "exit"))
		ms_exit(command, prompt);
	else if (!ft_strcmp(command->program, "env"))
		exe_fuc(command, prompt, ms_env);
	else if (!ft_strcmp(command->program, "export"))
		ms_export(command, prompt);
	else if (!ft_strcmp(command->program, "unset"))
		ms_unset(command, prompt);
	else
		path_command(command, env);
}

void	read_commands(t_command *commands, t_promptinfo *prompt, t_dict *env)
{
	int	i;

	i = -1;
	while (commands[++i].program)
		command_fork(&commands[i], prompt, env);
	i = -1;
	while (commands[++i].program)
		waitpid(commands[i].pid, NULL, 0);
	free_commands(commands);
}
