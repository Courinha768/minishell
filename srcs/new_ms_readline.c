// #include "../include/include.h"

// int	rl_dif_command_valid_char(char c)
// {
// 	return (c == '&' || c == '|');
// }

// int	rl_args_valid_char(char c)
// {
// 	return (c == '&' || c == '|' || c == '>' || c == '<');
// }

// int	rl_count_commands(char *cl)
// {
// 	int	i;
// 	int	counter;

// 	i = -1;
// 	counter = 0;
// 	while (cl[++i])
// 	{
// 		if (rl_dif_command_valid_char(cl[i]))
// 			counter++;
// 		if (cl[i + 1] == '&')
// 			i++;
// 	}
// 	return (counter + 1);
// }

// int	rl_nbr_of_args(char **tokens, int i)
// {
// 	int	counter;

// 	counter = 0;
// 	while (tokens[i] && !rl_args_valid_char(tokens[i++][0]))
// 		counter++;
// 	return (counter + 1);
// }

// t_command	nullcommand(void)
// {
// 	t_command	command;

// 	command.args = NULL;
// 	command.program = NULL;
// 	command.fdin = 0;
// 	command.fdout = 0;
// 	return (command);
// }

// t_command	rl_create_commands(char **tokens)
// {
// 	static int	s_i;
// 	t_command	command;
// 	int			i;

// 	if (!s_i)
// 		s_i = 0;
// 	if (!tokens[s_i])
// 		write(1, "+", 1);
// 	command.program = ft_strdup(tokens[s_i]);
// 	command.args = (char **)malloc(sizeof(char *) * rl_nbr_of_args(tokens, s_i));
// 	if (!command.args)
// 		return (nullcommand());
// 	i = 0;
// 	while (tokens[s_i] && !rl_args_valid_char(tokens[s_i][0]))
// 		command.args[i++] = ft_strdup(tokens[s_i++]);
// 	command.args[i] = NULL;
// 	command.fdin = 0;
// 	command.fdout = 1;
// 	handle_redd(&command, tokens, &s_i);
// 	if (tokens[s_i] && rl_dif_command_valid_char(tokens[s_i][0]))
// 		s_i++;
// 	if (!tokens[s_i])
// 		s_i = 0;
// 	return (command);
// }

// t_command	*ms_readline(char *prompt, char **env)
// {
// 	t_command	*commands;
// 	char		*command_line;
// 	char		**tokens;
// 	int			nbr_of_commands;
// 	int			i;

// 	(void)env;
// 	command_line = readline(prompt);
// 	if (!command_line[0])
// 		return (NULL);
// 	add_history(command_line);
// 	/*if (line not valid)
// 		return (NULL)*/
// 	nbr_of_commands = rl_count_commands(command_line);
// 	tokens = fancy_split(command_line, ' '); /*in ms_split we already switch the $vars*/
// 	commands = malloc(sizeof(t_command) * (nbr_of_commands + 1));
// 	if (!commands)
// 		return (NULL);
// 	i = 0;
// 	while (nbr_of_commands--)
// 		commands[i++] = rl_create_commands(tokens);
// 	commands[i] = nullcommand();
// 	rl_free_utils(command_line, prompt, tokens);
// 	return (commands);
// }