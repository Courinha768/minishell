/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:05:56 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/09 15:53:29 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

t_promptinfo	init_prompt(void)
{
	t_promptinfo	prompt;

	prompt.user = ft_strdup(getenv("USER"));
	prompt.colour = "\e[1;32m";
	prompt.init_pwd = getenv("PWD");
	prompt.pwd = ft_strdup(prompt.init_pwd);
	prompt.shenv = shenv_init(&prompt);
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
