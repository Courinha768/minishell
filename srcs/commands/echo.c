/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:16:15 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/09 17:23:01 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

//void	echo(t_command *command, int i)
//{
//	int		printlnb;
//	size_t	i;

//	printlnb = 1;
//	i = 1;
//	if (! strcmp(command->args[1], "-n"))
//	{
//		printlnb = 0;
//		i++;
//	}
//	while (command->args[i] != NULL)
//	{
//		ft_putstr_fd(command->args[i], 1);
//		i++;
//		if (command->args[i] != NULL)
//			ft_putchar_fd(' ', 1);
//	}
//	if (printlnb)
//		ft_putchar_fd('\n', 1);
//}

int	args_str_len(t_command	*command)
{
	int	i;
	int	j;
	int	counter;

	counter = 0;
	i = 0;
	if (!strcmp(command->args[1], "-n"))
		i++;
	while (command->args[++i])
	{
		j = -1;
		while (command->args[i][++j])
			counter++;
		counter++;
	}
	return (counter);
}

void	create_str(t_command *command, int i, int j, char *str)
{
	int	k;
	int	l;

	l = -1;
	while (command[i].args[++j])
	{
		k = -1;
		while (command[i].args[j][++k])
			str[++l] = command[i].args[j][k];
		if (command[i].args[j + 1])
			str[++l] = 32;
	}
	str[++l] = 0;
}

void	echo(t_command *command, int i)
{
	int		printlnb;
	char	*str;
	int		j;

	str = (char *)malloc(sizeof(char) * args_str_len(&(command[i])));
	if (!str)
		return ;
	j = 0;
	printlnb = 1;
	if (!strcmp(command[i].args[1], "-n"))
	{
		printlnb = 0;
		j++;
	}
	create_str(command, i, j, str);
	printf("%s", str);
	if (printlnb)
		printf("\n");
	if (command[i + 1].pipe_flag)
		command[i + 1].output = (void *)str;
}
