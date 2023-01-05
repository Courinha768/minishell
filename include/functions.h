#ifndef FUNCTIONS_H
# define FUNCTIONS_H

int			ft_strcmp(const char *s1, const char *s2);

void		ignore_shell_signal(void);
t_command	read_line(char *prompt);
void		clear_shell(void);

#endif