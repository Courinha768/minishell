/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:05:56 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/16 23:34:20 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

t_promptinfo	init_prompt(char **envp)
{
	t_promptinfo	prompt;

	prompt.user = ft_strdup(getenv("USER"));
	prompt.pwd = ft_strdup(getenv("PWD"));
	prompt.newenv = shenv_init(envp);
	prompt.colour = "\e[1;32m";
	return (prompt);
}

char	*create_prompt(t_promptinfo *prompt_struct)
{
	char	*temp_1;
	char	*temp_2;
	char	*prompt;

	temp_1 = ft_strjoin("minishell@", prompt_struct->user);
	temp_2 = ft_strjoin(temp_1, " #\033[0m ");
	prompt = ft_strjoin(prompt_struct->colour, temp_2);
	free(temp_1);
	free(temp_2);
	return (prompt);
}
