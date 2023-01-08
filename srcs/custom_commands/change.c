/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:33:13 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/08 18:33:02 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

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

void	change(t_command command, t_promptinfo *prompt)
{
	if ((command.args[1] && command.args[2] && command.args[3])
		|| !command.args[1])
		printf("change: Incorrect number of arguments\n");
	else if (!ft_strcmp(command.args[1], "colour"))
	{
		if (command.args[2] && !ft_strcmp(command.args[2], "help"))
		{
			printf("\e[4;37moptions:\e[4;0m\n \e[1;30m• black\n \e[1;31m• red\n ");
			printf("\e[1;32m• green\n \e[1;33m• yellow\n \e[1;34m• blue\n ");
			printf("\e[1;35m• mangenta\n \e[1;36m• cyan\n \e[1;37m• white\n\033[0m");
		}
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
