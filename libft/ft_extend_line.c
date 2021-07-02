#include "libft.h"

void *ft_extend_line(char **line, const char *word)
{
	size_t total_len;
	char *line_temp;

	total_len = ft_strlen(*line) + ft_strlen(word) + 1;
	line_temp = *line;
	if(!(*line = malloc(sizeof(char) * total_len)))
		return (NULL);
	ft_memset(*line, 0, total_len);
	ft_memcpy(*line, line_temp, ft_strlen(line_temp));
	ft_strlcat(*line, word, total_len);
	free(line_temp);
	return (*line);
}
