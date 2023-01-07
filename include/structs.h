/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:05:35 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/07 22:35:33 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_command {
	char	program[1024];
	char	args[1024][1024];
}	t_command;

typedef struct s_promptinfo {
	char	*user;
	char	*colour;
	char	*init_pwd;
}	t_promptinfo;

typedef struct s_info {
	char	token[1024][1024];
	char	*line;
	int		current_token;
	int		finnished;
}	t_info;

#endif
