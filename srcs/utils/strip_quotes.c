/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strip_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:23:13 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/17 22:19:46 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	quote_is_valid(char const c, char breaker)
{
	static int	inside_quote;
	static int	inside_squote;

	if (c == '\"')
	{
		if (!inside_quote)
			inside_quote = 1;
		else
			inside_quote = 0;
	}
	else if (c == '\'')
	{
		if (!inside_squote)
			inside_quote = 1;
		else
			inside_squote = 0;
	}
	else if (c == breaker && !inside_quote && !inside_squote)
		return (0);
	return (1);
}

void	remove_quote(char *token, int i)
{
	while (token[++i])
		token[i - 1] = token[i];
	token[i - 1] = 0;
}

void	build_new_token(int size, char **token, char *content)
{
	char	*new_token;
	int		i;
	int		j;
	int		k;

	new_token = (char *)ft_calloc(sizeof(char), size + 1);
	if (!new_token)
		return ;
	i = 0;
	j = -1;
	while ((*token)[++j] != '$')
		new_token[i++] = (*token)[j];
	k = -1;
	while (content[++k])
		new_token[i++] = content[k];
	j++;
	while (ft_isalnum((*token)[j]))
		j++;
	while ((*token)[j] && (*token)[++j])
		new_token[i++] = (*token)[j];
	new_token[i] = 0;
	free(*token);
	*token = new_token;
}

void	check_for_evars(char **token, t_dict *env, int i)
{
	char	str[1024];
	char	*content;
	int		j;
	int		s;

	j = 0;
	s = i;
	while (ft_isalnum((*token)[++i]))
		str[j++] = (*token)[i];
	str[j] = 0;
	content = dict_get(env, str);
	if (!content)
		content = "";
	s += ft_strlen(content);
	while ((*token)[i++])
		s++;
	build_new_token(s, token, content);
}

void	strip_quotes(t_command *commands, t_dict *env)
{
	int	i;
	int	j;
	int	k;
	int	inside_quote;
	int	inside_squote;

	k = -1;
	while (commands[++k].program)
	{
		i = -1;
		inside_quote = -1;
		inside_squote = -1;
		while (commands[k].args[++i])
		{
			j = -1;
			while ((j == -1 || commands[k].args[i][j]) && commands[k].args[i][++j])
			{
				if (commands[k].args[i][j] == '$' && inside_squote < 0)
					check_for_evars(&(commands[k].args[i]), env, j);
				if (commands[k].args[i][j] == '\"' && inside_squote < 0)
				{
					remove_quote(commands[k].args[i], j);
					j--;
					inside_quote *= -1;
				}
				else if (commands[k].args[i][j] == '\'' && inside_quote < 0)
				{
					remove_quote(commands[k].args[i], j);
					inside_squote *= -1;
				}
			}
		}
	}
}
