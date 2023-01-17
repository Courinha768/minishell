/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:33:13 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/08 19:32:52 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/include.h"

void	change_colour(t_promptinfo *prompt, char *new_colour)
{
	if (!ft_strcmp(new_colour, "black"))
		prompt->colour = BBLK;
	else if (!ft_strcmp(new_colour, "red"))
		prompt->colour = BRED;
	else if (!ft_strcmp(new_colour, "green"))
		prompt->colour = BGRN;
	else if (!ft_strcmp(new_colour, "yellow"))
		prompt->colour = BYEL;
	else if (!ft_strcmp(new_colour, "blue"))
		prompt->colour = BBLU;
	else if (!ft_strcmp(new_colour, "mangenta"))
		prompt->colour = BMAG;
	else if (!ft_strcmp(new_colour, "cyan"))
		prompt->colour = BCYN;
	else if (!ft_strcmp(new_colour, "white"))
		prompt->colour = BWHT;
	else
		printf("change colour: %s not found\n", new_colour);
}

void	print_change_help(void)
{
	printf("\e[4;37moptions:\e[4;0m\n \e[1;30m• black\n \e[1;31m• red\n ");
	printf("\e[1;32m• green\n \e[1;33m• yellow\n \e[1;34m• blue\n ");
	printf("\e[1;35m• mangenta\n \e[1;36m• cyan\n \e[1;37m• white\n\033[0m");
}

void	change(t_command command, t_promptinfo *prompt)
{
	if ((command.args[1] && command.args[2] && command.args[3])
		|| !command.args[1])
		printf("change: Incorrect number of arguments\n");
	else if (!ft_strcmp(command.args[1], "colour"))
	{
		if (command.args[2] && !ft_strcmp(command.args[2], "help"))
			print_change_help();
		else if (command.args[2])
			change_colour(prompt, command.args[2]);
		else
			printf("change colour: please insert a colour\n");
	}
	else if (!ft_strcmp(command.args[1], "username"))
	{
		if (command.args[2])
		{
			free(prompt->user);
			prompt->user = ft_strdup(command.args[2]);
		}
		else
			printf("change username: please insert a new username\n");
	}
	else
		printf("change: %s not found\n", command.args[1]);
}
