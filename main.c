/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:08:09 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/20 06:30:53 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/include.h"

int	main(int argc, char **argv, char **envp)
{
	t_promptinfo	prompt_info;
	t_command		*commands;
	char			*line;

	(void)argc;
	(void)argv;
	shell_signal();
	prompt_info = init_prompt(envp);
	while (!info()->finished)
	{
		line = ms_readline(&prompt_info);
		if (!line && printf("exit\n"))
			break ;
		if (!line[0])
		{
			free(line);
			continue ;
		}
		commands = create_commands(line, &prompt_info.newenv);
		free(line);
		if (commands)
			read_commands(commands, &prompt_info, &prompt_info.newenv);
	}
	free_promptinfo(&prompt_info);
	exit(info()->errorkeep);
}

// TODO:
// add error nbr on exit
// on exit, check if the arguments are nbrs (it leaves anyways)
// on exit, check if there is only on argument (it doesnt leave)
// FIXME:
// ctrl+C is printing 2 prompts when doing something like cat with no args
// NORMINETTE