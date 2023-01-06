/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:08:09 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/06 20:13:49 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/include.h"

//Improve this function
void	free_everything(t_promptinfo *prompt)
{
	free(prompt->colour);
}

// void	free_command(t_command *command)

t_info *info(){
	static t_info inf;

	return &inf;
}

int	main(void)
{
	t_promptinfo	prompt_info;
	//t_command		command;

	//ignore_shell_signal();
	clear_shell();
	prompt_info = init_prompt();
	while (1)
	{
		//command = 
		read_line(create_prompt(prompt_info));
		/*if (!ft_strcmp(command.program, "msexit"))
			break ;
		else
			check_command(command, &prompt_info);*/
		
	}
	free_everything(&prompt_info);
}
