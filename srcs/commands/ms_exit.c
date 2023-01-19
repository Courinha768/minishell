/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:30:57 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/19 15:42:41 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	ms_exit(t_command *command, t_promptinfo *prompt)
{
	//TODO:  add arguments
	(void)command;
	(void)prompt;
	info()->finished = 1;
	printf("exit\n");
}
