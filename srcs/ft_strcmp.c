#include "../include/include.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while(s1[i] || s2[i])
	{
		if (s2[i] != s2[i])
			return (1);
		if (!s1[i])
			break;
		i++;
	}
	return (0);
}