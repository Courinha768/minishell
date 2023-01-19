/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:58:28 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/19 02:42:38 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	print_commands(t_command *commands)
{
	int	i;
	int	j;

	i = -1;
	printf("=============\n");
	while (commands[++i].program)
	{
		j = -1;
		printf("fdin    : %d\n", commands[i].fdin);
		printf("fdout   : %d\n", commands[i].fdout);
		printf("program : %s\n", commands[i].program);
		printf("args    : ");
		while (commands[i].args[++j])
			printf("%s ", commands[i].args[j]);
		printf("\n");
		printf("=============\n");
	}
}
