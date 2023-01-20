/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:30:57 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/20 00:04:38 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	ms_exit(t_command *command, t_promptinfo *prompt)
{
	//TODO:  add arguments
	info()->finished = 1;
	(void)command;
	(void)prompt;
	printf("exit\n");
}
