#include "../include/include.h"


//trocar isto para receber os tokkens em vez da line
int	countcommands(char *line)
{
	int	i;
	int	counter;

	i = -1;
	counter = 1;
	while (line[++i])
	{
		if (line[i] == '|')
			counter++;
		if (line[i] == '>' || line[i] == '<')
		{
			counter++;
			if (line[i + 1] == '>' || line[i + 1] == '<')
				i++;
		}
		if (line[i] == '&')
		{
			counter++;
			i++;
		}
	}
	return (counter);
}

int	rl_is_valid(char c)
{
	return (c != '|' && c != '>' && c != '<' && c != '&');
}

int	countargs(char **tokens, int i)
{
	int	counter;

	while (tokens[i] && rl_is_valid(tokens[i][0]))
	{
		counter++;
		i++;
	}
	return (counter);
}

t_command	nullcommand(void)
{
	t_command command;

	command.args = NULL;
	command.program = NULL;
	command.fdin = 0;
	command.fdout = 0;
	command.redd_flag = 0;
	return (command);
}

t_command	createcommand(char **tokens)
{
	t_command	command;
	static int	static_current_token;
	int			current_token;
	int			i;

	if (!static_current_token)
		static_current_token = 0;
	command.fdin = 0;
	command.fdout = 1;
	command.redd_flag = 0;
	current_token = static_current_token;
	if (current_token)
		current_token++;
	command.program = ft_strdup(tokens[current_token]);
	command.args = (char **)malloc(sizeof(char *) * (countargs(tokens, current_token) + 1));
	if (!command.args)
		return (nullcommand());
	i = 0;
	while (tokens[current_token] && rl_is_valid(tokens[current_token][0]))
	{
		command.args[i++] = ft_strdup(tokens[current_token]);
		current_token++;
	}
	command.args[i] = NULL;
	//handle reddirects
	static_current_token = current_token;
	if (!tokens[current_token])
		static_current_token = 0;
	return (command);
}

// echo hello > cat | hello && goodbye

t_command	*read_line(char *prompt)
{
	int			nbr_of_commands;
	int			i;
	char		*line;
	char		**tokens;
	t_command	*commands;

	line = readline(prompt);
	free(prompt);
	//check if line is valid
	tokens = fancy_split(ft_strdup(line), ' ');
	nbr_of_commands = countcommands(line);
	free(line);
	commands = malloc(sizeof(t_command) * (nbr_of_commands + 1));
	if (!commands)
		return (NULL);
	i = 0;
	while (nbr_of_commands--)
	{
		commands[i] = createcommand(tokens);
		i++;
	}
	commands[i] = nullcommand();
	//strip_quotes(commands);
	i = -1;
	while (tokens[++i])
		free(tokens[i]);
	free(tokens);
	return (commands);
}
