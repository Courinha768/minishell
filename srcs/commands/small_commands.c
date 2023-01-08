/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:55:27 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/08 17:55:33 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	pwd_command(void)
{
	char	*pwd;

	pwd = getenv("PWD");
	printf("%s\n", pwd);
}

void	clear_command(void)
{
	clear_shell();
}

void	exit_command(void)
{
	info()->finnished = 1;
}
