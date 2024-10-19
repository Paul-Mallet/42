
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_is_set(char const *set, char const c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s1_cp;
	size_t	low;
	size_t	high;
	size_t	i;

	low = 0;
	while (ft_is_set(set, s1[low]))
		low++;
	high = ft_strlen(s1) - 1;
	while (ft_is_set(set, s1[high]))
		high--;
	s1_cp = (char *)malloc((((high + 1) - low) + 1) * sizeof(char));
	if (s1_cp == NULL)
		return (NULL);
	i = 0;
	while (low <= high)
	{
		s1_cp[i] = (char)s1[low];
		low++;
		i++;
	}
	s1_cp[i] = '\0';
	return (s1_cp);
}
/*
int	main(int ac, char **av)
{
	if (ac == 3)
		printf("%s\n", ft_strtrim(av[1], av[2]));
	else
		printf("Must have 2 arguments!");
	return (0);
}
*/
