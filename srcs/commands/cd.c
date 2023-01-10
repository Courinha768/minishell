/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:26:28 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/10 20:28:33 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	cd(t_command *command, t_promptinfo *prompt)
{
	if (chdir(command->args[1]) == -1)
	{
		printf("cd: no such file or directory %s\n", command->args[1]);
		return ;
	}
	free(prompt->pwd);
	prompt->pwd = getcwd(NULL, 0);
}
