/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:05:26 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/17 19:53:03 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

char			*create_prompt(t_promptinfo *prompt_struct);
char			*read_line(t_promptinfo *promptinfo);
t_command		*create_commands(char *line);

/* ========================================================================== */
/*                                COMMANDS                                    */
/* ========================================================================== */

void			read_commands(t_command *commands, t_promptinfo *prompt,
					t_dict *env);

void			ms_cd(t_command *command, t_promptinfo *prompt);
void			ms_clear(t_command *command, t_promptinfo *prompt);
void			ms_echo(t_command *command, t_promptinfo *prompt);
void			ms_exit(t_command *command, t_promptinfo *prompt);
void			ms_env(t_command *command, t_promptinfo *prompt);
void			ms_export(t_command *command, t_promptinfo *prompt);
void			ms_pwd(t_command *command, t_promptinfo *prompt);
void			ms_unset(t_command *command, t_promptinfo *prompt);

int				path_command(t_command *command, t_dict *env);

t_dict			shenv_init(char **envp);
void			d_envprint(char *keyval);
void			dictprint(t_dict *dict, void (*printstyle)(t_dict *));
void			envstyle(t_dict *dict);
void			exportstyle(t_dict *dict);

int				dodictorder(t_dict *dict, t_dict **least, size_t i);
t_dict			*shexport_init(t_dict *env);
void			shexport_orderalpha(t_dict **env);

/* ===========================CUSTOM_COMMANDS================================ */

void			change(t_command command, t_promptinfo *prompt);

/* ========================================================================== */
/*                           INIT_AND_END_FUNCS                               */
/* ========================================================================== */

void			free_commands(t_command *commands);
void			free_promptinfo(t_promptinfo *prompt_info);
void			dict_free(t_dict *dict);
void			dict_shallowfree(t_dict *dict);
void			dict_freeone(t_dict *dict);

t_promptinfo	init_prompt(char **envp);

void			rl_free_utils(char *cl, char *prompt, char **tokens);

/* ========================================================================== */
/*                                 UTILS                                      */
/* ========================================================================== */

void			exe_fuc(t_command *command, t_promptinfo *prompt,
					t_function fun);

size_t			strcmpwhr(const char *s1, const char *s2);
int				ft_charinside(char c, const char *s);
int				mtrxdo(char **mtrx, void *data,
					int (*func)(char, void *, size_t, size_t));
size_t			ft_mtrxlen(void **m);
int				ft_strcmp(const char *s1, const char *s2);

t_token			*token(void);

void			strip_quotes(char **tokens);

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

int				countcommands(char *line);
int				countargs(char **tokens, int i);
t_command		nullcommand(void);

/* =============================DICT UTILS=================================== */

size_t			ft_min(size_t a, size_t b);
size_t			ft_max(size_t a, size_t b);
void			ft_strswap(char **s1, char **s2);

int				antstrcmp(const char *s1, const char *s2);
void			dict_insert(t_dict *dict, size_t index, char *keyval);
void			d_iterprint(char *keyval);
void			dict_iter(t_dict *dict, void (*f)(char *));
char			*dict_getit(t_dict *dict, char *key);
size_t			dict_pos(t_dict *dict, char *key);
char			*dict_get(t_dict *dict, char *key);
t_dict			dict_new(size_t amount);
int				dict_add(t_dict *dict, char *keyval);
char			*dict_pop(t_dict *dict, char *key);
void			dict_shallowfree(t_dict *dict);

/* ========================================================================== */
/*                                 DEBUG                                      */
/* ========================================================================== */

void			print_commands(t_command *commands);
void			print_tokens(void);

#endif
