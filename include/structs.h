/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:16:07 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/16 19:41:32 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_dict {
	char		**env;
	size_t		cap;
	size_t		count; // is not the amount!!
}	t_dict;			   //   because there can be empty elements

typedef struct s_command {
	int		fdin;
	int		fdout;
	char	*program;
	char	**args;
	int		pid[100];
}	t_command;

typedef struct s_promptinfo {
	char	*user;
	char	*colour;
	char	*pwd;
	t_dict	newenv;
}	t_promptinfo;

typedef struct s_token {
	int		current_token;
	char	token[1024][1024];
}	t_token;

typedef struct s_info {
	int		finished;
	char	*line;
}	t_info;

#endif
