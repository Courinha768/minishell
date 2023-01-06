/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:33:13 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/06 20:14:12 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	change(t_command command, t_promptinfo *prompt)
{
	if (command.args[1] && command.args[2])
		printf("change: Incorrect number of arguments");
	if (!ft_strcmp(command.args[0], "colour"))
	{
		if (command.args[1] && !ft_strcmp(command.args[1], "help"))
		{
			printf("options:\n");
			printf(" \e[1;30mblack\n");
			printf(" \e[1;31mred\n");
			printf(" \e[1;32mgreen\n");
			printf(" \e[1;33myellow\n");
			printf(" \e[1;34mblue\n");
			printf(" \e[1;35mmangenta\n");
			printf(" \e[1;36mcyan\n");
			printf(" \e[1;37mwhite\n\033[0m");
		}
		if (command.args[1])
			change_colour(prompt, command.args[1]);
		else
			printf("change colour: please insert a colour\n");
	}
	else if (!ft_strcmp(command.args[0], "username"))
		prompt->user = command.args[1];
}

void	change_colour(t_promptinfo *prompt, char *new_colour)
{
	if (!ft_strcmp(new_colour, "black"))
		prompt->colour = "\e[1;30m";
	else if (!ft_strcmp(new_colour, "red"))
		prompt->colour = "\e[1;31m";
	else if (!ft_strcmp(new_colour, "green"))
		prompt->colour = "\e[1;32m";
	else if (!ft_strcmp(new_colour, "yellow"))
		prompt->colour = "\e[1;33m";
	else if (!ft_strcmp(new_colour, "blue"))
		prompt->colour = "\e[1;34m";
	else if (!ft_strcmp(new_colour, "mangenta"))
		prompt->colour = "\e[1;35m";
	else if (!ft_strcmp(new_colour, "cyan"))
		prompt->colour = "\e[1;36m";
	else if (!ft_strcmp(new_colour, "white"))
		prompt->colour = "\e[1;37m";
	else
		printf("change colour: %s not found\n", new_colour);
}
