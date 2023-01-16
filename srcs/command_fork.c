/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:10:54 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/16 23:06:55 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	exe_fuc(t_promptinfo *prompt, t_command *command, function fun)
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

void	command_fork(t_command *commands, t_promptinfo *prompt, t_dict *env)
{
	if (!ft_strcmp(commands->program, "change"))
		change(*commands, prompt);
	else if (!ft_strcmp(commands->program, "echo"))
		exe_fuc(prompt, commands, echo);
	else if (! ft_strcmp(commands->program, "cd"))
		cd(commands, prompt);
	else if (!ft_strcmp(commands->program, "pwd"))
		exe_fuc(prompt, commands, pwd_command);
	else if (!ft_strcmp(commands->program, "clear"))
		clear_command();
	else if (!ft_strcmp(commands->program, "exit"))
		exit_command();
	else if (! ft_strcmp(commands[i].program, "env"))
		dict_iter(&prompt->newenv, d_envprint);
	else if (! ft_strcmp(commands[i].program, "export"))
		func_export(commands[i], prompt);
	else if (! ft_strcmp(commands[i].program, "unset"))
		func_unset(commands[i], prompt)h. When you rebase develop t;
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
		printf("%s: command not found\n", commands->program);
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
