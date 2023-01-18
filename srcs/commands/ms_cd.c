/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:26:28 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/18 16:08:41 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	ms_cd(t_command *command, t_promptinfo *prompt)
{
	if (!command->args[1])
	{
		free(prompt->pwd);
		prompt->pwd = ft_strdup(dict_get(&prompt->newenv, "HOME"));
		chdir(prompt->pwd);
		return ;
	}
	if (chdir(command->args[1]) == -1)
	{
		printf("cd: no such file or directory %s\n", command->args[1]);
		return ;
	}
	free(prompt->pwd);
	prompt->pwd = getcwd(NULL, 0);
}
