/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:08:09 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/20 02:59:30 by aappleto         ###   ########.fr       */
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
			continue ;
		commands = create_commands(line, &prompt_info.newenv);
		free(line);
		if (commands)
			read_commands(commands, &prompt_info, &prompt_info.newenv);
	}
	free_promptinfo(&prompt_info);
	exit(info()->error);
}

// TODO:
// add $? on exit
// add echo &?
// no such file or directory is printing on less char
// ctrl+C is printing 2 prompts when doing something like >grep "something"
// ctrl+D is doing something weird to
// add cd -
// cat | cat | cat 'existing file'
// echo $ = seg fault