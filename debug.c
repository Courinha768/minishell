/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:58:28 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/08 18:58:30 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/include.h"

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
	while (commands[++i].program)
	{
		j = -1;
		if (i > 0)
			printf("=============\n");
		while (commands[i].args[++j])
			printf("%s\n", commands[i].args[j]);
	}
}
