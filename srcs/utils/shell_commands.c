/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:55:20 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/18 17:45:46 by amaria-d         ###   ########.fr       */
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

void sig_hnd(int sig){ (void)sig; printf("(SIG)"); }

/**
 * Process received signals
*/
void	shell_signal(void)
{
	signal(SIGINT, sig_print);
	signal(SIGQUIT, SIG_IGN);
}
