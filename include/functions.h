/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:05:26 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/07 20:06:24 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void			ignore_shell_signal(void);
void			read_line(char *prompt);
void			token(char *line);

/* ========================================================================== */
/*                                 PROMPT                                     */
/* ========================================================================== */

t_promptinfo	init_prompt(void);
char			*create_prompt(t_promptinfo prompt_struct);

/* ========================================================================== */
/*                                COMMANDS                                    */
/* ========================================================================== */

void			check_command(t_promptinfo *prompt);
t_command		read_token(void);
int				is_valid(void);

void			clear_shell(void);

void			change(t_command command, t_promptinfo *prompt);
void			change_colour(t_promptinfo *prompt, char *new_colour);

/* ========================================================================== */
/*                                  UTILS                                     */
/* ========================================================================== */

t_info			*info(void);
int				ft_strcmp(const char *s1, const char *s2);

#endif
