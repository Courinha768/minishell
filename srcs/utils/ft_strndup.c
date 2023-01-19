#include "../../include/include.h"

char	*ft_strndup(const char *s1, int start, int end)
{
	char	*dup;
	int		i;

	i = start;
	while (s1[i] && i < end)
		i++;
	dup = (char *)malloc(sizeof(char) * (i - start + 1));
	if (!dup)
		return (NULL);
	i = start;
	while (i < (int)ft_strlen(s1) && i < end)
	{
		dup[i - start] = s1[i];
		i++;
	}
	dup[i - start] = 0;
	return (dup);
}
