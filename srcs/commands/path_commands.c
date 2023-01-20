/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:26:41 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/20 11:38:07 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

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

static char	*find_path(t_command *command, t_dict *env)
{
	char	**splitpath;
	char	*command_path;
	int		i;

	i = -1;
	splitpath = define_path(env);
	if (!splitpath)
		return (NULL);
	if (command->program[0] == '/')
	{
		i = -1;
		while (splitpath[++i])
			free(splitpath[i]);
		free(splitpath);
		return (ft_strdup(command->program));
	}
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
	i = -1;
	while (splitpath[++i])
		free(splitpath[i]);
	free(splitpath);
	if (command_path)
		return (command_path);
	else
		return (ft_strndup(command->program, 2, END));
}

void	path_command(t_command *command, t_promptinfo *prompt)
{
	char	*path;
	int		pid;
	path = find_path(command, &prompt->newenv);
	if (access(path, F_OK | X_OK) == -1)
	{
		info()->errorkeep = errno;
		perror(path);
	}
	else
	{
		pid = fork();
		if (!pid)
		{
			dup2(command->fdout, 1);
			dup2(command->fdin, 0);
			closefds(command);
			execve(path, command->args, prompt->newenv.env);
			free(path);
			free_promptinfo(prompt);
			free_commands(command);
			exit(50);
		}
		command->pid = pid;
	}
	// command->pid = -2;
	closefds(command);
	free(path);
}
