#ifndef FUNCTIONS_H
# define FUNCTIONS_H

int			ft_strcmp(const char *s1, const char *s2);

void		ignore_shell_signal(void);
t_command	read_line(char *prompt);
void		clear_shell(void);

t_prompt	init_prompt(void);
char		*pwd_strip(t_prompt prompt);
char		*create_prompt(t_prompt prompt_struct);

char	*prompt_static(t_prompt prompt_struct, int a);

void	ctrl_idk();
int		exit_shell(int a);

#endif