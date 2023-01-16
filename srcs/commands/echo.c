/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:16:15 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/16 22:45:02 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

//int	args_str_len(t_command	*command)
//{
//	int	i;
//	int	j;
//	int	counter;

//	counter = 0;
//	i = 0;
//	if (!strcmp(command->args[1], "-n"))
//		i++;
//	while (command->args[++i] && is_valid2(command->args[i][0]))
//	{
//		j = -1;
//		while (command->args[i][++j])
//			counter++;
//		counter++;
//	}
//	return (counter);
//}

//void	create_str(t_command command, int j, char *str)
//{
//	int	k;
//	int	l;

//	l = -1;
//	while (command.args[++j] && is_valid2(command.args[j][0]))
//	{
//		k = -1;
//		while (command.args[j][++k])
//			str[++l] = command.args[j][k];
//		if (command.args[j + 1])
//			str[++l] = 32;
//	}
//	str[++l] = 0;
//}

//void	echo(t_command *command)
//{
//	int		printlnb;
//	char	*str;
//	int		j;

//	str = (char *)malloc(sizeof(char) * args_str_len(command));
//	if (!str)
//		return ;
//	j = 0;
//	printlnb = 1;
//	if (!strcmp(command->args[1], "-n"))
//	{
//		printlnb = 0;
//		j++;
//	}
//	create_str(*command, j, str);
//	ft_putstr_fd(str, command->fdout);
//	if (printlnb)
//		ft_putstr_fd("\n", command->fdout);
//	free(str);
//}

void	echo(t_promptinfo *prompt, t_command *command)
{
	int		printlnb;
	size_t	i;

	(void)prompt;
	printlnb = 1;
	i = 1;
	if (! strcmp(command->args[1], "-n"))
	{
		printlnb = 0;
		i++;
	}
	while (command->args[i] != NULL)
	{
		ft_putstr_fd(command->args[i], 1);
		i++;
		if (command->args[i] != NULL)
			ft_putchar_fd(' ', 1);
	}
	if (printlnb)
		ft_putchar_fd('\n', 1);
}
