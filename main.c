/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:08:09 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/16 15:07:25 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/include.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_promptinfo	prompt_info;
	char			*line;
	t_command		*commands;

	(void)argc;
	(void)argv;
	//ignore_shell_signal();
	// clear_shell();
	prompt_info = init_prompt(envp);
	info()->finished = 0;
	while (!info()->finished)
	{
		line = create_prompt(&prompt_info);
		add_history(line);
		commands = read_line(line);
		if (commands)
		{
			token()->current_token = 0;
			read_commands(commands, &prompt_info);
		}
	}
	free_promptinfo(&prompt_info);
}
