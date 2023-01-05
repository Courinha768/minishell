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

int	main(void)
{
	t_prompt	prompt;
	t_command	command;

	ignore_shell_signal();
	clear_shell();
	prompt = init_prompt();
	while (1)
	{
		command = read_line(create_prompt(prompt));
		if (!ft_strcmp(command.command, "msexit"))
			break;
	}
	free_everything(&prompt, &command);
}