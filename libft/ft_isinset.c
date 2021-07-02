#include "libft.h"

int	ft_isinset(char ch, const char *set)
{
	size_t idx;

	idx = 0;
	while (set[idx] != '\0')
	{
		if (set[idx] == ch)
			return (1);
		idx++;
	}
	return (0);
}
