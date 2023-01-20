/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:31:22 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/20 06:10:26 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/include.h"

void	ms_clear(t_command *command, t_promptinfo *prompt)
{
	(void)command;
	(void)prompt;
	clear_shell();
}
