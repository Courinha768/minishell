/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:05:26 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/08 17:34:27 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void			ignore_shell_signal(void);

/* ========================================================================== */
/*                                 PROMPT                                     */
/* ========================================================================== */

t_promptinfo	init_prompt(void);
char			*create_prompt(t_promptinfo prompt_struct);

/* ========================================================================== */
/*                             CREATE COMMANDS                                    */
/* ========================================================================== */

t_command		*read_line(char *prompt);
t_command		create_commands(void);
void			create_token(char *line);

int				args_counter(void);
int				count_commands(char *line);

t_token			*token(void);

/* ========================================================================== */
/*                                COMMANDS                                    */
/* ========================================================================== */

void			command_fork(t_promptinfo *prompt);
t_command		read_token(void);

void			clear_shell(void);

void			change(t_command command, t_promptinfo *prompt);
void			change_colour(t_promptinfo *prompt, char *new_colour);

void			echo(void);

/* ========================================================================== */
/*                                  UTILS                                     */
/* ========================================================================== */

int				ft_strcmp(const char *s1, const char *s2);
int				is_valid(char c);

#endif
