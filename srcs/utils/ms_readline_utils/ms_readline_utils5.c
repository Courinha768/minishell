#include "../../../include/include.h"

int	find_redirection(t_tokens token)
{
	if (token.redd.red_i)
		return (RED_I);
	else if (token.redd.red_o)
		return (RED_O);
	else if (token.redd.red_d)
		return (RED_D);
	else if (token.redd.red_a)
		return (RED_A);
	return (FALSE);
}

void	create_redirection(t_tokens token, int red_type, t_command *command)
{
	if (red_type == RED_I)
	{
		if (!access(token.redd.file, F_OK))
			command->fdin = open(token.redd.file, O_RDONLY , 0644);
		//else
			//ERROR MSG
	}
	else if (red_type == RED_O)
	{
		command->fdout = open(token.redd.file, O_WRONLY
				| O_CREAT | O_TRUNC, 0644);
	}
	else if (red_type == RED_D)
	{
		//still not sure
	}
	else if (red_type == RED_A)
	{
		command->fdout = open(token.redd.file, O_WRONLY
					| O_CREAT | O_APPEND, 0644);
	}
}

void	free_tokens(t_tokens *token)
{
	int	i;

	i = -1;
	while (token->tokens[++i])
		free(token->tokens[i]);
	free(token->tokens);
	free(token->redd.file);
}