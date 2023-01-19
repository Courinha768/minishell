#include "../../../include/include.h"

/*
Remember to free if u dont want the output
*/
char	*remove_token(char ***tokens, int i)
{
	char	*removed;

	removed = ft_strdup((*tokens)[i]);
	free((*tokens)[i]);
	(*tokens)[i] = NULL;
	//i--;
	while ((*tokens)[++i])
	{
		if ((*tokens)[i])
		{
			(*tokens)[i - 1] = ft_strdup((*tokens)[i]);
			free((*tokens)[i]);
			(*tokens)[i] = NULL;
		}
	}
	return (removed);
}

void	add_token(char ***tokens, char *new_token, int i)
{
	char	**new_tokens;
	int		j;

	new_tokens = malloc(sizeof(char *) * (tokens_len(*tokens) + 2));
	if (!new_tokens)
		return ;
	j = -1;
	while (++j < i)
		new_tokens[j] = ft_strdup((*tokens)[j]);
	new_tokens[j] = ft_strdup(new_token);
	while ((*tokens)[j - 1])
		new_tokens[j] = ft_strdup((*tokens)[j - 1]);
	new_tokens[j] = NULL;
	free(new_token);
	free(*tokens);
	*tokens = new_tokens;
}

void	add_multiple_tokens(char ***tokens, char **new_tokens, int i)
{
	int	j;

	j = -1;
	while (new_tokens[++j])
	{
		add_token(tokens, new_tokens[j], i);
		i++;
	}
	free(new_tokens);
}

int	last_token(char **tokens)
{
	int i;
	
	i = 0;
	while (tokens[i])
		i++;
	return (i - 1);
}

int	tokens_len(char **tokens)
{
	int i;
	
	i = 0;
	while (tokens[i])
		i++;
	return (i);
}
