/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:16:07 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/20 00:14:55 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_dict {
	char		**env;
	size_t		cap;
	size_t		count;
}	t_dict;

typedef struct s_command {
	int		fdin;
	int		fdout;
	char	*program;
	char	**args;
	int		pid;
}	t_command;

typedef struct s_promptinfo {
	char	*user;
	char	*colour;
	char	*pwd;
	t_dict	newenv;
}	t_promptinfo;

typedef struct s_info {
	int		finished;
	char	*line;
	int		errorkeep;
}	t_info;

typedef void	(*t_function)(t_command *command_arg, t_promptinfo *prompt_arg);

#endif
