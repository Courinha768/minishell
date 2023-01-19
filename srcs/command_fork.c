/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:10:54 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/19 16:58:29 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	exe_fuc(t_command *command, t_promptinfo *prompt, t_function fun)
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
		fun(command, prompt);
		free_promptinfo(prompt);
		free_commands(command);
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
		// ms_env(&prompt->newenv);
	else if (!ft_strcmp(command->program, "export"))
		ms_export(command, prompt);
	else if (!ft_strcmp(command->program, "unset"))
		ms_unset(command, prompt);
	// else if (path_command(command, env))
		// return ;
	// else
	// 	printf("%s: command not found\n", command->program);
	else
		path_command(command, env);
	//TODO: don't free line and have it accessible here. Mb in the prompt
	// if (errno)
	// 	perror(command->args[1]);
	//TODO: move perror logic to each function
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
	print_commands(commands);
	free_commands(commands);
}
