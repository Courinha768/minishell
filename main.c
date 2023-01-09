/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:08:09 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/09 15:12:31 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/include.h"

int	main(void)
{
	t_promptinfo	prompt_info;
	char			*line;
	t_command		*commands;

	//TODO: Signals
	//ignore_shell_signal();
	clear_shell();
	prompt_info = init_prompt();
	info()->finished = 0;
	while (!info()->finished)
	{
		line = create_prompt(&prompt_info);
		//TODO: a lot
		add_history(line);
		commands = read_line(line);
		token()->current_token = 0;
		read_commands(commands, &prompt_info);
	}
	free_promptinfo(&prompt_info);
}
