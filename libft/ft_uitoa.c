#include "libft.h"

static size_t	get_n_len(unsigned int n)
{
	size_t len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char			*ft_uitoa(unsigned int n)
{
	char	*res;
	size_t	len;

	len = get_n_len(n);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[0] = '0';
	res[len] = '\0';
	len--;
	while (n != 0)
	{
		res[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (res);
}
