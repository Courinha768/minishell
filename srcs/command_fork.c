/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:10:54 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/20 13:34:58 by amaria-d         ###   ########.fr       */
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
		exit(errno);
	}
	closefds(command);
	command->pid = pid;
}

static void	command_fork(t_command *command, t_promptinfo *prompt)
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
		path_command(command, prompt);
}

void	read_commands(t_command *commands, t_promptinfo *prompt)
{
	int	i;
	int	stat_val;

	i = -1;
	while (commands[++i].program)
		command_fork(&commands[i], prompt);
	i = -1;
	while (commands[++i].program)
	{
		if (commands[i].pid != -1)
		{
			wait(&stat_val);
			if (WIFEXITED(stat_val))
				info()->errorkeep = WEXITSTATUS(stat_val);
		}
	}
	free_commands(commands);
}
