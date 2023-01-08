/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:08:09 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/08 17:35:19 by aappleto         ###   ########.fr       */
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
		{
			free(commands[i].args[j]);
		}
	}
	free(commands);
}

int	main(void)
{
	t_promptinfo	prompt_info;
	t_command		*commands;

	//ignore_shell_signal();
	clear_shell();
	prompt_info = init_prompt();
	while (1)
	{
		commands = read_line(create_prompt(prompt_info));
		token()->current_token = 0;
		// while (info()->token[info()->current_token][0])
		// 	command_fork(&prompt_info);
		print_commands(commands);
		free_commands(commands);
	}
}
