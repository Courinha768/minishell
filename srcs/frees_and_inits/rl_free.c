#include "../../include/include.h"

void	rl_free_utils(char *cl, char *prompt, char **tokens)
{
	int	i;

	(void)cl;
	//free(cl);
	free(prompt);
	i = -1;
	while (tokens[++i])
		free(tokens[i]);
	free(tokens);
}