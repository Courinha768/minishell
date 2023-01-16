/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:08:09 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/16 23:43:54 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/include.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_promptinfo	prompt_info;
	char			*prompt;
	t_command		*commands;

	(void)argc;
	(void)argv;
	//ignore_shell_signal();
	//clear_shell();
	prompt_info = init_prompt(envp);
	info()->finished = 0;
	while (!info()->finished)
	{
		prompt = create_prompt(&prompt_info);
		//melhorar o readline
		commands = read_line(prompt);
		if (commands)
		{
			token()->current_token = 0;
			read_commands(commands, &prompt_info, &prompt_info.newenv);
		}
	}
	free_promptinfo(&prompt_info);
}
