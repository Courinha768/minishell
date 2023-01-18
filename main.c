/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:08:09 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/18 16:20:59 by amaria-d         ###   ########.fr       */
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
	shell_signal();
	//clear_shell();
	prompt_info = init_prompt(envp);
	*envp = *prompt_info.newenv.env;
	info()->finished = 0;
	while (!info()->finished)
	{
		//line = create_prompt(&prompt_info);
		//melhorar o readline
		line = read_line(&prompt_info); //Alert: frees prompt
		if (!line)
		{
			printf("exit\n");
			break ;
		}

		commands = create_commands(line, &prompt_info.newenv); //Alert: frees line
		free(line);
		if (commands)
		{
			token()->current_token = 0;
			read_commands(commands, &prompt_info, &prompt_info.newenv);
		}
	}
	free_promptinfo(&prompt_info);
}
