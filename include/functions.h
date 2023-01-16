/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:05:26 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/16 16:45:42 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

char			*create_prompt(t_promptinfo *prompt_struct);

t_command		*read_line(char *prompt);

void			command_fork(t_command *command, int i, t_promptinfo *prompt);

/* ========================================================================== */
/*                                COMMANDS                                    */
/* ========================================================================== */

void			read_commands(t_command *commands, t_promptinfo *prompt);

void			cd(t_command *command, t_promptinfo *prompt);

void			echo(t_command command);

t_dict	shenv_init(char **envp);
void			dictprint(t_dict *dict, void (*printstyle)(t_dict *));
void			envstyle(t_dict *dict);
void			exportstyle(t_dict *dict);

int				func_export(t_command command, t_promptinfo *prompt);
int				dodictorder(t_dict *dict, t_dict **least, size_t i);
t_dict			*shexport_init(t_dict *env);
void			shexport_orderalpha(t_dict **env);

void			pwd_command(t_promptinfo *prompt, t_command commands);
void			clear_command(void);
void			exit_command(void);
		
		

/* ========================================================================== */
/*                            CUSTOM_COMMANDS                                 */
/* ========================================================================== */

void			change(t_command command, t_promptinfo *prompt);
void			print_change_help(void);
void			change_colour(t_promptinfo *prompt, char *new_colour);

/* ========================================================================== */
/*                           INIT_AND_END_FUNCS                               */
/* ========================================================================== */

void			free_commands(t_command *commands);
void			free_promptinfo(t_promptinfo *prompt_info);
void			dict_free(t_dict *dict);
void			dict_shallowfree(t_dict *dict);
void			dict_freeone(t_dict *dict);

t_promptinfo	init_prompt(char **envp);

/* ========================================================================== */
/*                                 UTILS                                      */
/* ========================================================================== */

int				antstrcmp(const char *s1, const char *s2);
 --cont_dict *dict, char *key);
void			dict_insert(t_dict **dict, size_t index, t_dict *new);
void	d_iterprint(char *keyval);

int				ft_charinside(char c, const char *s);

int				mtrxdo(char **mtrx, void *data,
					int (*func)(char, void *, size_t, size_t));

size_t			ft_mtrxlen(void **m);

int				ft_strcmp(const char *s1, const char *s2);

t_token			*token(void);
t_info			*info(void);

void			clear_shell(void);
void			ignore_shell_signal(void);

int				is_valid(char c);
int				is_valid2(char c);
int				rl_is_valid(char c);

int				line_valid(char **tokens);

char			**fancy_split(char *s, char c);

void			handle_redd(t_command *command, char **tokens,
					int *current_token);

void			strip_quotes(char **tokens);

/* ========================================================================== */
/*                                 DEBUG                                      */
/* ========================================================================== */

void			print_commands(t_command *commands);
void			print_tokens(void);

#endif
