/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:55:27 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/09 15:12:31 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	pwd_command(void)
{
	char	*pwd;

	pwd = getenv("PWD");
	printf("%s\n", pwd);
}

void	printworkdirec(t_promptinfo *prompt)
{
	printf("%s\n", prompt->pwd);
}

void	clear_command(void)
{
	clear_shell();
}

void	exit_command(void)
{
	info()->finished = 1;
}
