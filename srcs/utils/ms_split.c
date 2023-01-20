/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:02:49 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/20 14:35:25 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	s_token_counter(char *s)
{
	int	i;
	int	counter;
	int	in_quotes;
	int	in_squotes;

	i = -1;
	counter = 0;
	in_quotes = -1;
	in_squotes = -1;
	while (s[++i])
	{
		if (s[i] == ' ' && in_quotes < 0 && in_squotes < 0)
			counter++;
		else if (s[i] == '\"')
			in_quotes *= -1;
		else if (s[i] == '\'')
			in_squotes *= -1;
	}
	return (counter + 1);
}

int	s_t_size_counter(char *s, int i)
{
	int	counter;
	int	in_quotes;
	int	in_squotes;

	counter = 0;
	in_quotes = -1;
	in_squotes = -1;
	if (i > 0)
		i--;
	while (s[i] && (s[++i] != ' ' || in_quotes > 0 || in_squotes > 0))
	{
		if (s[i] == '\"')
			in_quotes *= -1;
		else if (s[i] == '\'')
			in_squotes *= -1;
		counter++;
	}
	return (counter + 1);
}

int	splitinin(char *s, char **split, int *i, int j)
{
	static int	in_quotes0 = -1;
	static int	in_quotes1 = -1;
	int			k;
	
	k = 0;
	while (s[*i] && (s[*i] != ' ' || in_quotes0 > 0 || in_quotes1 > 0))
	{
		if (s[*i] == '\"' && in_quotes1 < 0)
			in_quotes0 *= -1;
		else if (s[*i] == '\'' && in_quotes0 < 0)
			in_quotes1 *= -1;
		split[j][k++] = s[(*i)++];
	}
	split[j][k] = 0;
	return k;
}

int	splitinside(char *s, char **split)
{
	int	i;
	int	j;
	int	in_quotes[2];
	
	in_quotes[0] = -1;
	in_quotes[1] = -1;
	i = -1;
	j = 0;
	while ((i == -1 || s[i]) && s[++i])
	{
		split[j] = (char *)malloc(sizeof(char) * (s_t_size_counter(s, i) + 1));
		if (!split)
			return (0);
		split[j][splitinin(s, split, &i, j)] = 0;
		while (s[i] && s[i + 1] && s[i + 1] == ' ')
			i++;
		j++;
	}
	split[j] = 0;
	return (1);
}

char	**ms_split(char *s)
{
	char	**split;

	split = (char **)malloc(sizeof(char *) * (s_token_counter(s) + 1));
	if (!split)
		return (NULL);
	if (! splitinside(s, split))
		return (NULL);
	free(s);
	return (split);
}
