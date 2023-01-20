/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_readline_utils8.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 02:30:25 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/20 05:26:14 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/include.h"

static int	inside_quotes(int c)
{
	static int	inside_quotes;
	static int	inside_squotes;

	if (c < 0)
	{
		inside_quotes = -1;
		inside_squotes = -1;
		return (TRUE);
	}
	if (!inside_quotes)
	{
		inside_quotes = -1;
		inside_squotes = -1;
	}
	if (c == '\"' && inside_squotes < 0)
		inside_quotes *= -1;
	else if (c == '\'' && inside_quotes < 0)
		inside_squotes *= -1;
	if (inside_squotes > 0)
		return (TRUE);
	return (FALSE);
}

int	ms_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	if (!needle[0])
		return (-1);
	if ((int)len < 0)
		len = 4092;
	while (haystack[i] && i < (int)len)
	{
		j = 0;
		a = inside_quotes(haystack[i]);
		if (!a)
			while (haystack[i + j] == needle[j] && i + j < (int)len)
				if (!needle[1 + j++] && inside_quotes(-1))
					return (i);
		i++;
	}
	inside_quotes(-1);
	return (-1);
}

int	evar_stopers(char *s, int i)
{
	int	j;
	int	inside_quotes;
	int	inside_squotes;

	j = -1;
	if (s[i] != '$')
		return (FALSE);
	inside_quotes = -1;
	inside_squotes = -1;
	while (++j < i)
	{
		if (s[j] == '\"' && inside_squotes < 0)
			inside_quotes *= -1;
		else if (s[j] == '\'' && inside_quotes < 0)
			inside_squotes *= -1;
	}
	if (inside_squotes < 0)
		return (TRUE);
	return (FALSE);
}

int	evar_stopers2(char *s, int i)
{
	int	j;
	int	inside_quotes;
	int	inside_squotes;

	j = -1;
	if (s[i] != '~' || (s[i - 1] && s[i - 1] != ' ')
		|| (s[i + 1] && s[i + 1] != ' ' && s[i + 1] != '/'))
		return (FALSE);
	inside_quotes = -1;
	inside_squotes = -1;
	while (++j < i)
	{
		if (s[j] == '\"' && inside_squotes < 0)
			inside_quotes *= -1;
		else if (s[j] == '\'' && inside_quotes < 0)
			inside_squotes *= -1;
	}
	if (inside_quotes < 0 && inside_squotes < 0)
		return (TRUE);
	return (FALSE);
}

void	replace_key(char **str, char *old_key, char *new_key)
{
	int		first;
	int		i;
	int		j;
	char	temp1[1024];
	char	temp2[1024];

	first = ms_strnstr(*str, old_key, -1);
	i = -1;
	while (++i < first - 1)
		temp1[i] = (*str)[i];
	temp1[i++] = 0;
	while (ft_isalnum((*str)[i]))
		i++;
	j = 0;
	while ((*str)[++i - 1])
		temp2[j++] = (*str)[i - 1];
	temp2[j] = 0;
	free(*str);
	*str = ft_strjoin3(temp1, new_key, temp2);
}
