/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:58:28 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/09 14:44:27 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	print_tokens(void)
{
	int	i;

	i = -1;
	while (token()->token[++i][0])
		printf("%s\n", token()->token[i]);
}

void	print_commands(t_command *commands)
{
	int	i;
	int	j;

	i = -1;
	printf("=============\n");
	while (commands[++i].args)
	{
		j = -1;
		printf("pipe_flag = %d\n", commands[i].pipe_flag);
		if (commands[i].pipe_flag)
			printf("output = %s\n", (char *)commands[i].output);
		while (commands[i].args[++j])
			printf("%s\n", commands[i].args[j]);
		printf("=============\n");
	}

}
