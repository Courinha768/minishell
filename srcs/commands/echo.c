/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:16:15 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/10 20:35:09 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	args_str_len(t_command	*command)
{
	int	i;
	int	j;
	int	counter;

	counter = 0;
	i = 0;
	if (!strcmp(command->args[1], "-n"))
		i++;
	while (command->args[++i] && is_valid2(command->args[i][0]))
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
	while (command[i].args[++j] && is_valid2(command[i].args[j][0]))
	{
		k = -1;
		while (command[i].args[j][++k])
			str[++l] = command[i].args[j][k];
		if (command[i].args[j + 1])
			str[++l] = 32;
	}
	if (!(command[i].pipe_flag > 1))
		l++;
	str[l] = 0;
}

void	echo_flag_handler(t_command *command, int i, char *str)
{
	int	k;

	k = 0;
	if (command[i].pipe_flag == 5)
	{
		while (command[i].args[k][0] != '>')
			k++;
		write_into_file(str, command[i].args[k + 1]);
	}
	if (command[i + 1].pipe_flag)
		command[i + 1].output = ft_strdup(str);
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
	echo_flag_handler(command, i, str);
	free(str);
}
