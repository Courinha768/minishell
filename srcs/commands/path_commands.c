/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:26:41 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/20 17:46:05 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	check_is_dir(char *path)
{
	struct stat	f;

	if (stat(path, &f) == -1)
		return (FALSE);
	if (S_ISDIR(f.st_mode))
		return (TRUE);
	return (FALSE);
}

static void	chldforkclose(t_command *command, t_promptinfo *prompt, char *path)
{
	signal(SIGINT, SIG_DFL);
	dup2(command->fdout, 1);
	dup2(command->fdin, 0);
	closefds(command);
	execve(path, command->args, prompt->newenv.env);
	info()->errorkeep = errno;
	free(path);
	free_promptinfo(prompt);
	free_commands(command);
	exit(info()->errorkeep);
}

void	path_command(t_command *command, t_promptinfo *prompt)
{
	char		*path;
	int			pid;

	if (access(command->program, F_OK | X_OK) == -1 && command->program[0])
		path = find_path(command, &prompt->newenv);
	else
		path = ft_strdup(command->program);
	if (check_is_dir(path))
		printf("%s: Is a directory\n", path);
	if (access(path, F_OK | X_OK) == -1)
	{
		info()->errorkeep = 127;
		ft_putstr_fd(command->program, 2);
		ft_putstr_fd(": command not found\n", 2);	
	}
	else
	{
		pid = fork();
		if (!pid)
			chldforkclose(command, prompt, path);
		command->pid = pid;
	}
	closefds(command);
	free(path);
}
