#include "../include/include.h"

void	ignore_shell_signal(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

t_command	read_line(char *prompt)
{
	t_command	command;
	char		*line;
	char		**split;
	int			i;

	line = readline(prompt);
	split = ft_split(line, ' ');
	command.command = split[0];
	i = 1;
	while(split[i])
		i++;
	command.arguments = (char **)malloc(sizeof(char *) * i);
	i = 0;
	while(split[++i])
		command.arguments[i - 1] = split[i];
	command.arguments[i - 1] = NULL;
	i = -1;
	while (split[++i])
		free(split[i]);
	return (command);
}

void	clear_shell(void)
{
	write(1, "\e[1;1H\e[2J", 11);
}


