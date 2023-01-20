/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:31:07 by amaria-d          #+#    #+#             */
/*   Updated: 2023/01/20 18:08:04 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_READLINE_H
# define MS_READLINE_H

# define RED_IN "<"
# define CRED_IN '<'
# define RED_OUT ">"
# define CRED_OUT '>'
# define RED_APP ">>"
# define RED_IDK "<<"
# define PIPE '|'
# define TRUE 1
# define FALSE 0

# define PIPE_AHEAD 1
# define PIPE_BEHIND 2

# define RED_I 1
# define RED_O 2
# define RED_D 3
# define RED_A 4

# define END 1024

typedef struct s_reddirec {
	int		red_i;
	int		red_o;
	int		red_d;
	int		red_a;
	char	*file;
}	t_reddirec;

typedef struct s_pipeflags {
	int	pipe_behind;
	int	pipe_ahead;
}	t_pipeflags;

typedef struct s_tokens {
	char		**tokens;
	t_pipeflags	pipe;
	t_reddirec	redd;
}	t_tokens;

void		change_pipe_flags(t_tokens *token, int flag_to_change);
void		change_redd_flags(t_tokens *token, int flag_to_change);
void		add_redd_file(	t_tokens *token, char *file);
void		reset_all_flags(t_tokens *token);
int			is_redirection(char *token);

char		*remove_token(char ***tokens, int i);
void		add_token(char ***tokens, char *new_token, int i);
void		add_multiple_tokens(char ***tokens, char **new_tokens, int i);
int			last_token(char **tokens);
int			tokens_len(char **tokens);

int			is_stopers(char *s, int i);
int			need_2_split(char *str);
char		**split_tokens(char *token_2_split);

t_tokens	create_token_struct(char **split);
t_tokens	null_token_struct(void);
int			nbr_of_struct_tokens(char **split);

void		free_tokens(t_tokens *token);
void		create_redirection(t_tokens token,
				int red_type, t_command *command);

int			find_redirection(t_tokens token);
t_command	create_command(t_tokens	*token);
t_command	null_command(void);

t_tokens	*create_tokens(char **split);
char		**ms_split2(char *line);
void		check_for_redirection(t_tokens **tokens);
void		create_pipes_and_redirections(t_tokens *token, t_command *command);
char		**ft_strstrdup(char **tokens);

void		remove_quotes(t_command **commands);

int			is_all_space(char *str);

t_command	nullcommand(void);

void		replace_key(char **str, char *old_key, char *new_key);
int			has_stopers(char *s);
int			evar_stopers2(char *s, int i);
int			evar_stopers(char *s, int i);
int			ms_strnstr(const char *haystack, const char *needle, size_t len);

void		place_evars(t_command **commands, t_dict *env);

#endif