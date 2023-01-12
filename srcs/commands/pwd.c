/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:31:36 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/11 17:04:20 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	pwd_command(t_promptinfo *prompt, t_command command)
{
	ft_putstr_fd(prompt->pwd, command.fdout);
}
