

#include <stdio.h>
#include <bsd/string.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	//https://man.freebsd.org/cgi/man.cgi?query=strnstr&sektion=3
}

int	main(void)
{
	const char	*big = "big little test";
	const char	little[] = "little";
	size_t		len = 6; //n chars to search

	printf("%s\n", ft_strnstr(big, little, len));
	printf("%s\n", strnstr(big, little, len));
	return (0);
}
