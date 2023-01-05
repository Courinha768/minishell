#include "./include/include.h"

void	free_everything(t_prompt *prompt, t_command *command)
{
	int	i;

	free(prompt->colour);
	free(command->command);
	i = -1;
	while (command->arguments[++i])
		free(command->arguments[i]);
}

void	change_colour(t_prompt *prompt, char *new_colour)
{
	if (!ft_strcmp(new_colour, "black"))
		prompt->colour = "\e[1;30m";
	if (!ft_strcmp(new_colour, "red"))
		prompt->colour = "\e[1;31m";
	if (!ft_strcmp(new_colour, "green"))
		prompt->colour = "\e[1;32m";
	if (!ft_strcmp(new_colour, "yellow"))
		prompt->colour = "\e[1;33m";
	if (!ft_strcmp(new_colour, "blue"))
		prompt->colour = "\e[1;34m";
	if (!ft_strcmp(new_colour, "mangenta"))
		prompt->colour = "\e[1;35m";
	if (!ft_strcmp(new_colour, "cyan"))
		prompt->colour = "\e[1;36m";
	if (!ft_strcmp(new_colour, "white"))
		prompt->colour = "\e[1;37m";
}

char	*prompt_static(t_prompt prompt_struct, int a)
{
	static char	*prompt;

	if (a)
		prompt = create_prompt(prompt_struct);
	return (prompt);
}

void	change(t_command command, t_prompt *prompt)
{
	if (!ft_strcmp(command.arguments[0], "colour"))
	{
		if (!ft_strcmp(command.arguments[1], "help"))
		{
			printf("options:\nblack\nred\ngreen\nyellow\nblue");
			printf("\nmangenta\ncyan\nwhite\n");
		}
		change_colour(prompt, command.arguments[1]);
	}
	else if (!ft_strcmp(command.arguments[0], "username"))
		prompt->user = command.arguments[1];
}

void	check_command(t_command command, t_prompt *prompt)
{
	if (!ft_strcmp(command.command, "change"))
		change(command, prompt);
	else if (!ft_strcmp(command.command, "pwd"))
		printf("%s\n", getenv("PWD"));
	else if (!ft_strcmp(command.command, "clear"))
		clear_shell();
	else if (!ft_strcmp(command.command, "exit"))
	{
		free_everything(prompt, &command);
		kill(getppid(), SIGKILL);
	}
	else
		printf("%s: command not found\n", command.command);
}

int	main(void)
{
	t_prompt	prompt;
	t_command	command;

	ignore_shell_signal();
	clear_shell();
	prompt = init_prompt();
	while (1)
	{
		prompt_static(prompt, 1);
		command = read_line(create_prompt(prompt));
		if (!ft_strcmp(command.command, "msexit"))
			break;
		else
			check_command(command, &prompt);
	}
	free_everything(&prompt, &command);
}