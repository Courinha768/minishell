/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:26:28 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/09 12:31:30 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

/* Changes the directory
*/
void	cd(t_command *command, t_promptinfo *prompt)
{
	if (chdir(command->args[1]) == -1)
	{
		printf("cd: no such file or directory %s\n", command->args[1]);
		return ;
	}
	free(prompt->pwd);
	//Alert: Allocation
	prompt->pwd = getcwd(NULL, 0);
}
