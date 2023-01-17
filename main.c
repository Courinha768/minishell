/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:08:09 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/17 17:27:50 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/include.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_promptinfo	prompt_info;
	t_command		*commands;
	char			*line;
	
	(void)argc;
	(void)argv;
	ignore_shell_signal();
	//clear_shell();
	prompt_info = init_prompt(envp);
	info()->finished = 0;
	while (!info()->finished)
	{
		// prompt = create_prompt(&prompt_info);
		//melhorar o readline
		line = read_line(&prompt_info); //Alert: frees prompt
		commands = create_commands(line); //Alert: frees line
		if (commands)
		{
			token()->current_token = 0;
			read_commands(commands, &prompt_info, &prompt_info.newenv);
		}
	}
	free_promptinfo(&prompt_info);
}
