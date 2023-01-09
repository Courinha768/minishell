/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:59:00 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/09 17:19:16 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	free_commands(t_command *commands)
{
	int	i;
	int	j;

	i = -1;
	while (commands[++i].program)
	{
		j = -1;
		free(commands[i].program);
		//free(commands[i].output);
		while (commands[i].args[++j])
			free(commands[i].args[j]);
		free(commands[i].args);
	}
	free(commands);
}

void	free_promptinfo(t_promptinfo *prompt_info)
{
	free(prompt_info->pwd);
	free(prompt_info->user);
}
