/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:55:20 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/17 23:25:25 by amaria-d         ###   ########.fr       */
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
}

void sig_hnd(int sig){ (void)sig; printf("(SIG)"); }


void	shell_signal(void)
{
	// struct sigaction act;
	// sigset_t		ignset;

	// SIGINT and SIGQUIT working!
	//Alert: ^C will show up and that's fine
	signal(SIGINT, sig_print);
	signal(SIGQUIT, SIG_IGN);
	
	// sigfillset(&act.sa_mask);
	// sigemptyset(&act.sa_mask);
	// sigaddset(&act.sa_mask, SIGINT);
	// sigaddset(&act.sa_mask, SIGQUIT);

	// act.sa_handler = SIG_IGN;
	// act.sa_flags = 0;
	
	// sigaction(SIGINT, &act, NULL);
	// sigaction(SIGQUIT, &act, NULL);
	



	// signal(SIGINT, sig_hnd);
	// termios.c_cc[VEOF] = 0; // ^C
	// termios.c_cc[VINTR] = 0; // ^D
// 	signal(SIGTSTP, SIG_IGN);
}
