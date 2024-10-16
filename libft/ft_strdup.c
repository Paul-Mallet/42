

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	int	i;
	int	s_len;
	char	*str;

	s_len = ft_strlen(s);
	str = (char *)malloc((s_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i]) //s[i++]?
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	main(void)
{
	const char	*s = "test";

	printf("%s\n", ft_strdup(s));
	printf("%s\n", strdup(s));
	return (0);
}
