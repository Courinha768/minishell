/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:55:20 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/20 14:05:39 by amaria-d         ###   ########.fr       */
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
//TODO: disactivate this when not in interactive mode
void	shell_signal(void)
{
	struct sigaction	sigsig;

	sigsig.sa_flags = 0;
	sigemptyset(&sigsig.sa_mask);
	sigaddset(&sigsig.sa_mask, SIGQUIT);
	sigaddset(&sigsig.sa_mask, SIGINT);
	sigsig.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sigsig, NULL);
	sigsig.sa_handler = sig_print;
	sigaction(SIGINT, &sigsig, NULL);
}
