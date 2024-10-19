
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_is_delim(char const s_c, char c)
{
	if (s_c == c)
		return (1);
	return (0);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (!ft_is_delim(s[i], c))
		{
			while (!ft_is_delim(s[i], c))
				i++;
			cnt++;
		}
		else
			i++;
	}
	return (cnt);
}

char	*ft_strdup_split(char const *s, char c)
{
	char	*str;
	size_t	i;

	i = 0;
	while (!ft_is_delim(s[i], c) && s[i])
		i++;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (!ft_is_delim(s[i], c) && s[i])
	{
		str[i] = (char)s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	words;
	size_t	i;
	size_t	j;

	words = count_words(s, c);
	arr = (char **)malloc((words + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[j])
	{
		while (ft_is_delim(s[j], c) && s[j])
			j++;
		if (s[j] == '\0')
			break ;
		arr[i] = ft_strdup_split(&s[j], c);
		while (!ft_is_delim(s[j], c) && s[j])
			j++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
/*
int	main(int ac, char **av)
{
	char	**arr;
	int	i;

	if (ac == 3 && ft_strlen(av[2]) == 1)
	{
		arr = ft_split(av[1], av[2][0]);
		i = 0;
		while (arr[i] != NULL)
			printf("%s\n", arr[i++]);
	}
	else
		printf("Must have 2 valid arguments!");
	return (0);
}
*/
