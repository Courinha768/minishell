#include "include/include.h"

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

char	**ms_split(char *s)
{

}