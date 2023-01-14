/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:59:00 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/14 18:25:27 by aappleto         ###   ########.fr       */
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

//void	dict_freeone(t_dict *dict)
//{
//	free(dict->key);
//	free(dict->value);
//	free(dict);
//}

//void	dict_free(t_dict *dict)
//{
//	t_dict	*after;

//	//TODO: Proctections
//	while (dict != NULL)
//	{
//		after = dict->next;
//		dict_freeone(dict);
//		dict = after;
//	}
//}

//void	dict_shallowfree(t_dict *dict)
//{
//	t_dict	*after;

//	while (dict != NULL)
//	{
//		after = dict->next;
//		free(dict);
//		dict = after;
//	}
//}
