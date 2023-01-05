#include "../include/include.h"

t_prompt	init_prompt(void)
{
	t_prompt	prompt;

	prompt.user = getenv("USER");
	prompt.colour = ft_strdup("\e[1;32m");
	prompt.init_pwd = getenv("PWD");
	return(prompt);
}

char	*pwd_strip(t_prompt prompt)
{
	char	*current_pwd;
	char	*relative_pwd;
	int		i;
	int		j;

	i = 0;
	current_pwd = getenv("PWD");
	while (current_pwd[i] == prompt.init_pwd[i] && current_pwd[i])
		i++;
	j = i;
	while (current_pwd[i])
		i++;
	relative_pwd = (char *)malloc(sizeof(char) * (i - j) + 1);
	i = j;
	while (current_pwd[i])
	{
		relative_pwd[i - j] = current_pwd[i];
		i++;
	}
	relative_pwd[i - j] = 0;
	return(relative_pwd);
}

char	*create_prompt(t_prompt prompt_struct)
{
	char	*prompt;
	char	*name;
	char	*name2;
	char	*pwd;

	name = ft_strjoin("minishell@", prompt_struct.user);
	name2 = ft_strjoin(name, " #\033[0m ");
	pwd = ft_strjoin(name2, pwd_strip(prompt_struct));
	prompt = ft_strjoin(prompt_struct.colour, pwd);
	free(name);
	free(name2);
	free(pwd);
	return (prompt);
}