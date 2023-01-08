/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:08:09 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/08 18:59:07 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/include.h"

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
	}
	free_promptinfo(&prompt_info);
}
