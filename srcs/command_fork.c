/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:10:54 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/16 23:53:25 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

static void	exe_fuc(t_promptinfo *prompt, t_command *command, function fun)
{
	int	pid;

	pid = fork();
	if (!pid)
	{
		dup2(command->fdout, 1);
		if (command->fdout != 1)
			close(command->fdout);
		dup2(command->fdin, 0);
		if (command->fdin != 0)
			close(command->fdin);
		fun(prompt, command);
		free_promptinfo(prompt);
		exit(1);
	}
	if (command->fdout != 1)
		close(command->fdout);
	if (command->fdin != 0)
		close(command->fdin);
	command->pid = pid;
}

static void	command_fork(t_command *command, t_promptinfo *prompt, t_dict *env)
{
	if (!ft_strcmp(command->program, "change"))
		change(*command, prompt);
	else if (!ft_strcmp(command->program, "echo"))
		exe_fuc(prompt, command, ms_echo);
	else if (! ft_strcmp(command->program, "cd"))
		exe_fuc(prompt, command, ms_cd);
	else if (!ft_strcmp(command->program, "pwd"))
		exe_fuc(prompt, command, ms_pwd);
	else if (!ft_strcmp(command->program, "clear"))
		exe_fuc(prompt, command, ms_clear);
	else if (!ft_strcmp(command->program, "exit"))
		exe_fuc(prompt, command, ms_exit);
	else if (!ft_strcmp(command->program, "env"))
		dict_iter(&prompt->newenv, d_envprint);
	else if (!ft_strcmp(command->program, "export"))
		func_export(*command, prompt);
	else if (!ft_strcmp(command->program, "unset"))
		func_unset(*command, prompt);
	else if (path_command(command, env))
		return ;
	else
		printf("%s: command not found\n", command->program);
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
	//print_commands(commands);
	free_commands(commands);
}
