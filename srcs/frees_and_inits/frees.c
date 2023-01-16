/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:59:00 by aappleto          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/16 16:45:30 by amaria-d         ###   ########.fr       */
=======
/*   Updated: 2023/01/16 15:03:08 by amaria-d         ###   ########.fr       */
>>>>>>> Remaking prompt_init
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
	dict_free(prompt_info->shenv);
}
