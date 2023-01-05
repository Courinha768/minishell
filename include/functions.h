/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:05:26 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/05 13:10:44 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void		free_everything(t_prompt *prompt, t_command *command);

t_prompt	init_prompt(void);
char		*create_prompt(t_prompt prompt_struct);
void		change(t_command command, t_prompt *prompt);
void		change_colour(t_prompt *prompt, char *new_colour);
char		*prompt_static(t_prompt prompt_struct, int a);

void		ignore_shell_signal(void);
t_command	read_line(char *prompt);
void		clear_shell(void);

int			ft_strcmp(const char *s1, const char *s2);

void		check_command(t_command command, t_prompt *prompt);

#endif
