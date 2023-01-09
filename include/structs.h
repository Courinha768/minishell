/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:05:35 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/09 12:33:12 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_command {
	char	*program;
	char	**args;
}	t_command;

typedef struct s_promptinfo {
	char	*user;
	char	*colour;
	char	*init_pwd;
	char	*pwd;
}	t_promptinfo;

typedef struct s_token {
	int		current_token;
	char	token[1024][1024];
}	t_token;

typedef struct s_info {
	int		finnished;
	char	*line;
}	t_info;

#endif
