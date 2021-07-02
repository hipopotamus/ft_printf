#include "ft_printf.h"

void *ft_printf_getbuffer(t_printf_condition *condition, const char *word, 
		size_t word_len)
{
	size_t total_len;
	char *line_temp;
	size_t idx;
	size_t line_len;

	line_len= condition->line_len;
	total_len = line_len + word_len + 1;
	line_temp = condition->line;
	if(!(condition->line = malloc(sizeof(char) * total_len)))
		return (NULL);
	idx = 0;
	while (idx < line_len + word_len)
	{
		if (idx < line_len)
			(condition->line)[idx] = line_temp[idx];
		else
			(condition->line)[idx] = word[idx];
		condition->line_idx++;
		idx++;
	}
	condition->line_len = idx;
	free(line_temp);
	return (condition->line);
}
