/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:05:26 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/10 14:16:10 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void			ignore_shell_signal(void);
void			free_commands(t_command *commands);
void			free_promptinfo(t_promptinfo *prompt_info);

void			print_commands(t_command *commands);
void			print_tokens(void);

/* ========================================================================== */
/*                                 PROMPT                                     */
/* ========================================================================== */

t_promptinfo	init_prompt(void);
char			*create_prompt(t_promptinfo *prompt_struct);

/* ========================================================================== */
/*                             CREATE COMMANDS                                */
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

void			read_commands(t_command *commands, t_promptinfo *prompt);
void			command_fork(t_command *command, int i, t_promptinfo *prompt);

void			clear_shell(void);

void			pwd_command(t_promptinfo *prompt, t_command *commands, int i);
void			clear_command(void);
void			exit_command(void);

void			change(t_command command, t_promptinfo *prompt);
void			change_colour(t_promptinfo *prompt, char *new_colour);

//void			echo(void);
//void			echo(t_command *command);
void			echo(t_command *command, int i);

void			cd(t_command *command, t_promptinfo *prompt);

/* ========================================================================== */
/*                                  UTILS                                     */
/* ========================================================================== */

int				ft_strcmp(const char *s1, const char *s2);
int				is_valid(char c);
int				line_valid(char c, char d);
t_info			*info(void);

int				ft_charinside(char c, const char *s);

t_dict	*dict_new(char *key, char *val);

int	dict_add(t_dict *dict, char *key, char *val);

char	*dict_get(t_dict *dict, char *key);

void	dict_iter(t_dict *dict, void (*f)(t_dict *));

void	dictprint(t_dict *dict, void (*printstyle)(t_dict *));

void	envstyle(t_dict *dict);

void	exportstyle(t_dict *dict);

t_dict	*shenv_init(t_promptinfo *prompt);

t_dict	*shexport_init(t_dict *shenv);

size_t	ft_mtrxlen(void **m);

int	func_export(t_command command, t_promptinfo *prompt);

void	lstswap(t_dict **a, t_dict **b);

int	lstdo(t_dict **lst, t_dict **data, int (*func)(t_dict *, t_dict **, size_t));

t_dict	*dictget_it(t_dict *dict, ssize_t index);

size_t	dictkeymin(t_dict *dict);

int	antstrcmp(const char *s1, const char *s2);

#endif
