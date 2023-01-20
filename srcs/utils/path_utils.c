/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:49:49 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/20 14:04:53 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

static char	**define_path(t_dict *env)
{
	char	**path;
	char	*p;

	p = dict_get(env, "PATH");
	if (!p)
		return (NULL);
	path = ft_split(p, ':');
	return (path);
}

char	*test_relpath(t_command *command, char **splitpath)
{
	char	*command_path;
	int		i;

	i = -1;
	while (splitpath[++i])
	{
		command_path = ft_strjoin3(splitpath[i], "/", command->program);
		if (command_path && !access(command_path, F_OK))
			break ;
		if (command_path)
		{
			free(command_path);
			command_path = NULL;
		}
	}
	return (command_path);
}

char	*find_path(t_command *command, t_dict *env)
{
	char	**splitpath;
	char	*command_path;
	int		i;

	splitpath = define_path(env);
	if (!splitpath)
		return (NULL);
	if (command->program[0] != '/')
		command_path = test_relpath(command, splitpath);
	i = -1;
	while (splitpath[++i])
		free(splitpath[i]);
	free(splitpath);
	if (command_path)
		return (command_path);
	else
		return (ft_strdup(command->program));
}
