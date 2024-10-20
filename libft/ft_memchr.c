
#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	//
}

int	main(int ac, char **av)
{
	char	*str;

	if (ac == 2)
	{
		//printf("\n", ft_memchr("test", 'a', 3 * sizeof(char)));
		str = memchr(av[1], 'a', 4);
		printf("%s\n", str);
	}
	return (0);
}

