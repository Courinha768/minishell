/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fancy_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:06:27 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/11 19:16:38 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	tokencounter(char const *s, char c)
{
	int	i;
	int	counter;
	int	inside_quote;
	int	inside_squote;

	i = -1;
	counter = 0;
	inside_quote = 0;
	inside_squote = 0;
	while (s[++i])
	{
		if (s[i] == '\"')
		{
			if (!inside_quote)
				inside_quote = 1;
			else
				inside_quote = 0;
		}
		else if (s[i] == '\'')
		{
			if (!inside_squote)
				inside_quote = 1;
			else
				inside_squote = 0;
		}
		else if (s[i] == c && !inside_quote && !inside_squote)
		{
			counter++;
			while (s[i] == c)
				i++;
		}
	}
	return (counter + 1);
}

int	tokenlen(char const *s, int i, char c)
{
	int	counter;
	int	inside_quote;
	int	inside_squote;

	counter = 0;
	inside_quote = 0;
	inside_squote = 0;
	while (s[++i] && (s[i] != c || inside_quote || inside_squote))
	{
		if (s[i] == '\"')
		{
			if (!inside_quote)
				inside_quote = 1;
			else
				inside_quote = 0;
		}
		else if (s[i] == '\'')
		{
			if (!inside_squote)
				inside_quote = 1;
			else
				inside_squote = 0;
		}
		counter++;
	}
	return (counter + 1);
}

int	fsplit_is_valid(char const c, char breaker)
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

char	**fancy_split(char *s, char c)
{
	char	**fsplit;
	int		i;
	int		s_i;
	int		s_j;

	fsplit = (char **)malloc(sizeof(char *) * (tokencounter(s, c) + 1));
	if (!fsplit)
		return (NULL);
	i = -1;
	s_i = 0;
	while (s[++i])
	{
		s_j = 0;
		if (s[i] != c)
		{
			fsplit[s_i] = (char *)malloc(tokenlen(s, i, c) + 1);
			if (!fsplit[s_i])
				return (NULL);
			while (s[i] && fsplit_is_valid(s[i], c))
				fsplit[s_i][s_j++] = s[i++];
			fsplit[s_i++][s_j] = 0;
		}
		if (!s[i])
			break ;
	}
	fsplit[s_i] = NULL;
	free(s);
	return (fsplit);
}
