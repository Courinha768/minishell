/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:08:09 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/08 18:56:49 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/include.h"

void	print_tokens(void)
{
	int	i;

	i = -1;
	while (token()->token[++i][0])
		printf("%s\n", token()->token[i]);
}

void	print_commands(t_command *commands)
{
	int	i;
	int	j;

	i = -1;
	while (commands[++i].program)
	{
		j = -1;
		if (i > 0)
			printf("=============\n");
		while (commands[i].args[++j])
			printf("%s\n", commands[i].args[j]);
	}
}

void	free_commands(t_command *commands)
{
	int	i;
	int	j;

	i = -1;
	while (commands[++i].program)
	{
		j = -1;
		free(commands[i].program);
		while (commands[i].args[++j])
			free(commands[i].args[j]);
		free(commands[i].args);
	}
	free(commands);
}

void	free_promptinfo(t_promptinfo *prompt_info)
{
	free(prompt_info->user);
}

int	main(void)
{
	t_promptinfo	prompt_info;
	t_command		*commands;

	//ignore_shell_signal();
	clear_shell();
	prompt_info = init_prompt();
	info()->finnished = 0;
	while (!info()->finnished)
	{
		commands = read_line(create_prompt(prompt_info));
		token()->current_token = 0;
		read_commands(commands, &prompt_info);
		//print_commands(commands);
	}
	free_promptinfo(&prompt_info);
}
