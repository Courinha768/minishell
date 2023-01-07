/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:08:09 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/07 19:38:39 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/include.h"

int	main(void)
{
	t_promptinfo	prompt_info;

	//ignore_shell_signal();
	clear_shell();
	info()->finnished = 0;
	prompt_info = init_prompt();
	while (!info()->finnished)
	{
		read_line(create_prompt(prompt_info));
		info()->current_token = 0;
		while (info()->token[info()->current_token][0])
			check_command(&prompt_info);
	}
}
