/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:26:28 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/19 16:56:22 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

static char	*cd_strjoin(char *s1, char *s2)
{
	unsigned int	counter1;
	unsigned int	counter2;
	char			*join;

	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)));
	if (!join)
		return (NULL);
	counter1 = 0;
	counter2 = 1;
	while (s1[counter1])
	{
		join[counter1] = s1[counter1];
		counter1++;
	}
	if (s2[counter2 - 1])
		while (s2[counter2])
			join[counter1++] = s2[counter2++];
	join[counter1] = '\0';
	free(s2);
	return (join);
}

int	actualcd(char *newdir)
{
	int	ret;
	
	ret = chdir(newdir);
	if (errno)
		perror(newdir);
	return (ret);
}

void	ms_cd(t_command *command, t_promptinfo *prompt)
{
	if (!command->args[1])
	{
		free(prompt->pwd);
		prompt->pwd = ft_strdup(dict_get(&prompt->newenv, "HOME"));
		actualcd(prompt->pwd);
		return ;
	}
	else if (command->args[1][0] == '~')
	{
		command->args[1] = cd_strjoin(dict_get(&prompt->newenv, "HOME"),
			command->args[1]);
	}
	if (actualcd(command->args[1]) == -1)
	{
		// printf("cd: no such file or directory %s\n", command->args[1]);
		return ;
	}
	free(prompt->pwd);
	prompt->pwd = getcwd(NULL, 0);
}
