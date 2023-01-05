/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:05:56 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/05 17:57:23 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

t_info	init_prompt(void)
{
	t_info	prompt;

	prompt.user = getenv("USER");
	prompt.colour = ft_strdup("\e[1;32m");
	prompt.init_pwd = getenv("PWD");
	return (prompt);
}

char	*create_prompt(t_info prompt_struct)
{
	char	*prompt;
	char	*name;
	char	*name2;

	name = ft_strjoin("minishell@", prompt_struct.user);
	name2 = ft_strjoin(name, " #\033[0m ");
	prompt = ft_strjoin(prompt_struct.colour, name2);
	free(name);
	free(name2);
	return (prompt);
}

void	change(t_command command, t_info *prompt)
{
	if (!ft_strcmp(command.args[0], "colour"))
	{
		if (!ft_strcmp(command.args[1], "help"))
		{
			printf("options:\nblack\nred\ngreen\nyellow\nblue");
			printf("\nmangenta\ncyan\nwhite\n");
		}
		change_colour(prompt, command.args[1]);
	}
	else if (!ft_strcmp(command.args[0], "username"))
		prompt->user = command.args[1];
}

void	change_colour(t_info *prompt, char *new_colour)
{
	if (!ft_strcmp(new_colour, "black"))
		prompt->colour = "\e[1;30m";
	if (!ft_strcmp(new_colour, "red"))
		prompt->colour = "\e[1;31m";
	if (!ft_strcmp(new_colour, "green"))
		prompt->colour = "\e[1;32m";
	if (!ft_strcmp(new_colour, "yellow"))
		prompt->colour = "\e[1;33m";
	if (!ft_strcmp(new_colour, "blue"))
		prompt->colour = "\e[1;34m";
	if (!ft_strcmp(new_colour, "mangenta"))
		prompt->colour = "\e[1;35m";
	if (!ft_strcmp(new_colour, "cyan"))
		prompt->colour = "\e[1;36m";
	if (!ft_strcmp(new_colour, "white"))
		prompt->colour = "\e[1;37m";
}

char	*prompt_static(t_info prompt_struct, int a)
{
	static char	*prompt;

	if (a)
		prompt = create_prompt(prompt_struct);
	return (prompt);
}
