/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:05:56 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/17 19:05:27 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

char	*trygetenv(char *key)
{
	char	*val;

	val = getenv(key);
	if (val == NULL)
		return (ft_strdup(key));
	return (ft_strdup(val));
}

t_promptinfo	init_prompt(char **envp)
{
	t_promptinfo	prompt;

	prompt.user = trygetenv("USER");
	prompt.pwd = trygetenv("PWD");
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
