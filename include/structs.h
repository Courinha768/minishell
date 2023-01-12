/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:16:07 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/12 20:14:16 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_dict {
	char			*key;
	char			*value;
	struct s_dict	*next;
}	t_dict;

typedef struct s_command {
	int		fdin;
	int		fdout;
	char	*program;
	char	**args;
}	t_command;

// typedef struct s_command {
// 	int		pipe_flag;
// 	int		fdin;
// 	int		fdout;
// 	char	*output;
// 	char	*program;
// 	char	**args;
// }	t_command;

typedef struct s_promptinfo {
	char	*user;
	char	*colour;
	char	*pwd;
	t_dict	*shenv;
	t_dict	*shexport; // Shallow copy of shenv
}	t_promptinfo;		// ordered alphabetically

typedef struct s_token {
	int		current_token;
	char	token[1024][1024];
}	t_token;

typedef struct s_info {
	int		finished;
	char	*line;
}	t_info;

#endif
