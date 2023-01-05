/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:06:02 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/05 13:06:04 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	ctrl_c()
{
	t_prompt	null_prompt;

	null_prompt.colour = NULL;
	null_prompt.init_pwd = NULL;
	null_prompt.user = NULL;
	printf("\n%s", prompt_static(null_prompt, 0));
}

void	ignore_shell_signal(void)
{
	signal(SIGINT, ctrl_c);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

t_command	read_line(char *prompt)
{
	t_command	command;
	char		*line;
	char		**split;
	int			i;

	line = readline(prompt);
	split = ft_split(line, ' ');
	command.command = split[0];
	i = 1;
	while (split[i])
		i++;
	command.arguments = (char **)malloc(sizeof(char *) * i);
	i = 0;
	while (split[++i])
		command.arguments[i - 1] = ft_strdup(split[i]);
	command.arguments[i - 1] = NULL;
	i = -1;
	return (command);
}

void	clear_shell(void)
{
	write(1, "\e[1;1H\e[2J", 11);
}
