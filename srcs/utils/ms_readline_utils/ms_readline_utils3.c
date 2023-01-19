#include "../../../include/include.h"

static int	find_stoper(char *str)
{
	int i;
	
	i = -1;
	while (str[++i])
		if (str[i] == PIPE)
			break;
	return (i);
}

char	**split_tokens(char *token_2_split)
{
	int		i;
	int		pipe_char;
	char	**splited_tokens;


	splited_tokens = malloc(sizeof(char *) * 4);
	if (!splited_tokens)
		return (NULL);
	i = -1;
	pipe_char = find_stoper(token_2_split);
	splited_tokens[0] = ft_strndup(token_2_split, 0, pipe_char);
	splited_tokens[1] = ft_strdup("|");
	splited_tokens[2] = ft_strndup(token_2_split, pipe_char + 1, END);
	splited_tokens[3] = NULL;
	free(token_2_split);
	return (splited_tokens);
}

int	need_2_split(char *str)
{
	int	i;
	int	valid;

	i = -1;
	valid = FALSE;
	while (str[++i])
	{
		if (isalnum(str[i]))
			valid = TRUE;
		if (str[i] == PIPE && valid)
			return (TRUE);
	}
	return (FALSE);
}
