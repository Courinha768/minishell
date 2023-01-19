/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:55:20 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/19 16:14:20 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	clear_shell(void)
{
	write(1, "\e[1;1H\e[2J", 11);
}

void	sig_print(int signal)
{
	(void)signal;
	rl_replace_line("", 0);
	printf("\n");
	rl_on_new_line();
	rl_redisplay();
}

/**
 * Process received signals
*/
void	shell_signal(void)
{
	//Alert: Do NOT change the order these are in!!!
	//TODO: disactivate this when not in interactive mode
	signal(SIGQUIT, SIG_IGN);
	// signal(SIGINT, sig_print);
}
