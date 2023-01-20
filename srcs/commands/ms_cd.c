/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:26:28 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/20 05:37:22 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

//static char	*cd_strjoin(char *s1, char *s2)
//{
//	unsigned int	counter1;
//	unsigned int	counter2;
//	char			*join;

//	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)));
//	if (!join)
//		return (NULL);
//	counter1 = 0;
//	counter2 = 1;
//	while (s1[counter1])
//	{
//		join[counter1] = s1[counter1];
//		counter1++;
//	}
//	if (s2[counter2 - 1])
//		while (s2[counter2])
//			join[counter1++] = s2[counter2++];
//	join[counter1] = '\0';
//	// free(s2);
//	return (join);
//}

/**
 * Newdir will NOT be freed
*/
void	actualcd(t_promptinfo *prompt, char *newdir)
{
	if (chdir(newdir) == -1)
		return (perror(newdir));
	dict_add(&prompt->newenv, ft_strjoin("OLDPWD=", prompt->pwd));
	free(prompt->pwd);
	prompt->pwd = getcwd(NULL, 0);
	dict_add(&prompt->newenv, ft_strjoin("PWD=", prompt->pwd));
}

void	ms_cd(t_command *command, t_promptinfo *prompt)
{
	char	*newdir;

	if (!command->args[1])
		actualcd(prompt, dict_get(&prompt->newenv, "HOME"));
	else if (command->args[1][0] == '-' && !(command->args[1][1]))
	{
		newdir = ft_strdup(dict_get(&prompt->newenv, "OLDPWD"));
		actualcd(prompt, newdir);
		free(newdir);
	}
	else
		actualcd(prompt, command->args[1]);
}
