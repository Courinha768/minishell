/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:06:02 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/06 20:18:00 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

// void	ctrl_c()
// {
// 	t_info	null_prompt;

// 	null_prompt.colour = NULL;
// 	null_prompt.init_pwd = NULL;
// 	null_prompt.user = NULL;
// 	printf("\n%s", prompt_static(null_prompt, 0));
// }

void	clear_shell(void)
{
	write(1, "\e[1;1H\e[2J", 11);
}

void	ignore_shell_signal(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	token(char *line)
{
	int			j;
	int			k;

	j = 0;
	k = 0;
	while (line && *line)
	{
		if (*line != ' ')
			info()->token[j][k++] = *line++;
		else
		{		
			j++;			
			k = 0;
			while (*line == 32)
				line++;
		}	
		info()->token[j][k] = 0;
		info()->token[j + 1][0] = 0;		
	}	
}

void	join_quotations(void)
{
	int	i;
	int	j;
	int	flag;

	j = -1;
	flag = 1;
	while (info()->token[++j][0])
	{
		i = -1;
		while (info()->token[j][++i])
		{
			if (info()->token[j][i] == 34 && !flag)
				flag = 1;
			else if (info()->token[j][i] == 39 && !flag)
				flag = 2;
			else if (info()->token[j][i] == 39 && flag == 2)
				flag = 0;
			else if (info()->token[j][i] == 34 && flag == 1)
				flag = 0;
		}
		if (flag)
		{
			ft_strlcat(info()->token[j], info()->token[j + 1], 1024);
			j--;
		}
	}
}

t_command read_line(char *prompt)
{
	t_command	command;
	char		*line;
	
	line = readline(prompt);
	free(prompt);
	token(line);
	//fazer funcao que une tokens com aspas
	command.program = NULL;
	return (command);
}
