/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:05:26 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/05 17:57:24 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void		free_everything(t_info *prompt, t_command *command);

t_info	init_prompt(void);
char		*create_prompt(t_info prompt_struct);
void		change(t_command command, t_info *prompt);
void		change_colour(t_info *prompt, char *new_colour);
char		*prompt_static(t_info prompt_struct, int a);

void		ignore_shell_signal(void);
t_command	read_line(char *prompt);
void		clear_shell(void);

int			ft_strcmp(const char *s1, const char *s2);

void		check_command(t_command command, t_info *prompt);

#endif
