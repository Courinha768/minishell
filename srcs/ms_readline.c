/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-d <amaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:05:52 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/20 10:49:42 by amaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	replace_1(char **token, t_dict *env)
{
	int		dollar_sign;
	char	key[1024];
	int		i;
	char	*temp;

	dollar_sign = ms_strnstr(*token, "$", -1);
	i = 0;
	if ((*token)[dollar_sign + 1] == '?')
		key[i++] = '?';
	else
		while (ft_isalnum((*token)[++dollar_sign]))
			key[i++] = (*token)[dollar_sign];
	key[i] = 0;
	if (!ft_strcmp(key, "?\0"))
	{
		temp = ft_itoa(info()->errorkeep);
		replace_key(token, key, temp);
		free(temp);
	}
	else
		replace_key(token, key, dict_get(env, key));
}

void	place_evars(t_command **commands, t_dict *env)
{
	int	i;
	int	j;
	int	a;

	i = -1;
	while ((*commands)[++i].program)
	{
		j = -1;
		while ((*commands)[i].args[++j])
		{
			a = has_stopers((*commands)[i].args[j]);
			if (a == 1)
				replace_1(&((*commands)[i].args[j]), env);
			else if (a == 2)
				replace_key(&((*commands)[i].args[j]), "~",
					dict_get(env, "HOME"));
			if (a)
				j--;
			a = 0;
		}
	}
}

int	is_special(char *str)
{
	if (!ft_strcmp(str, "<") || !ft_strcmp(str, "<<"))
		return (TRUE);
	else if (!ft_strcmp(str, ">") || !ft_strcmp(str, ">>"))
		return (TRUE);
	else if (!ft_strcmp(str, "|"))
		return (TRUE);
	return (FALSE);
	
}

int	check_line(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
	{
		if (i > 0 && is_special(split[i]) && is_special(split[i - 1]))
		{
			printf("minishell: syntax error near unexpected token `%s'\n", split[i]);
			info()->errorkeep = 2;
			return (TRUE);
		}
		if (is_special(split[i]) && !split[i + 1])
		{
			printf("minishell: syntax error near unexpected token `newline'\n");
			info()->errorkeep = 2;
			return (TRUE);
		}
	}
	return (FALSE);
}

t_command	*free_char_list(char ***list)
{
	int	i;

	i = -1;
	while ((*list)[++i])
		free((*list)[i]);
	free(*list);
	return (NULL);
}

t_command	*create_commands(char *line, t_dict *env)
{
	char		**split;
	t_tokens	*tokens;
	t_command	*commands;
	int			i;

	(void)env;
	split = ms_split2(ft_strdup(line));
	if (check_line(split))
		return (free_char_list(&split));
	tokens = create_tokens(split);
	check_for_redirection(&tokens);
	i = 0;
	while (tokens[i].tokens && tokens[i].tokens[0])
		i++;
	commands = malloc(sizeof(t_command) * (i + 1));
	if (!commands)
		return (NULL);
	i = -1;
	while (tokens[++i].tokens && tokens[i].tokens[0])
		commands[i] = create_command(&(tokens[i]));
	commands[i] = nullcommand();
	free(tokens);
	place_evars(&commands, env);
	remove_quotes(&commands);
	return (commands);
}

char	*ms_readline(t_promptinfo *prompt_info)
{
	char	*prompt;
	char	*command_line;

	prompt = create_prompt(prompt_info);
	command_line = readline(prompt);
	free(prompt);
	if (!command_line || !command_line[0])
		return (command_line);
	add_history(command_line);
	return (command_line);
}
