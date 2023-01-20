/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:08:09 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/20 05:11:00 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/include.h"

void	update_shlvl(t_promptinfo *prompt)
{
	int		shlvl;
	char	*shlvl_c;

	shlvl_c = dict_get(&prompt->newenv, "SHLVL");
	shlvl = ft_atoi(shlvl_c) + 1;
	dict_add(&prompt->newenv, ft_strjoin("SHLVL", ft_itoa(shlvl)));
}

int	main(int argc, char **argv, char **envp)
{
	t_promptinfo	prompt_info;
	t_command		*commands;
	char			*line;

	(void)argc;
	(void)argv;
	shell_signal();
	prompt_info = init_prompt(envp);
	update_shlvl(&prompt_info); // only works when entering the first time not when entering minishell inside minishell
	while (!info()->finished)
	{
		line = ms_readline(&prompt_info);
		if (!line && printf("exit\n"))
			break ;
		if (!line[0])
			continue ;
		commands = create_commands(line, &prompt_info.newenv);
		free(line);
		if (commands)
			read_commands(commands, &prompt_info, &prompt_info.newenv);
	}
	free_promptinfo(&prompt_info);
	exit(info()->error);
}

// TODO:
// add error nbr on exit
// add echo &?
// on exit, check if the arguments are nbrs (it leaves anyways)
// on exit, check if there is only on argument (it doesnt leave)
// FIXME:
// ctrl+C is printing 2 prompts when doing something like cat with no args
// ctrl+D is correct but its making error msgs weird
// NORMINETTE