#include "../../include/include.h"

static int	strjoin3_size(char const *s1, char const *s2, char const *s3)
{
	int		size[3];

	size[0] = 0;
	size[1] = 0;
	size[2] = 0;
	if (s1)
		size[0] = ft_strlen(s1);
	if (s2)
		size[1] = ft_strlen(s2);
	if (s3)
		size[2] = ft_strlen(s3);
	return (size[0] + size[1] + size[2]);
}

char	*ft_strjoin3(char const *s1, char const *s2, char const *s3)
{
	char	*join;
	int		counter[3];

	join = (char *)malloc(sizeof(char) * (strjoin3_size(s1, s2, s3) + 1));
	if (!join)
		return (NULL);
	counter[0] = -1;
	counter[1] = -1;
	counter[2] = -1;
	while (s1 && s1[++counter[0]])
		join[counter[0]] = s1[counter[0]];
	while (s2 && s2[++counter[1]])
		join[counter[0]++] = s2[counter[1]];
	while (s3 && s3[++counter[2]])
		join[counter[0]++] = s3[counter[2]];
	join[counter[0]] = 0;
	return (join);
}
