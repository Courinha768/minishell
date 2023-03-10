/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:05:39 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/17 19:25:31 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	rl_free_utils(char *cl, char *prompt, char **tokens)
{
	int	i;

	free(cl);
	free(prompt);
	i = -1;
	while (tokens[++i])
		free(tokens[i]);
	free(tokens);
}
