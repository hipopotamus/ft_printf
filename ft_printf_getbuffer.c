/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getbuffer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:45:35 by sungwopa          #+#    #+#             */
/*   Updated: 2021/07/05 15:08:08 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_getbuffer(t_printf_condition *condition, const char *word,
		size_t word_len)
{
	size_t	total_len;
	char	*line_temp;
	size_t	idx;
	size_t	word_idx;

	total_len = condition->line_len + word_len + 1;
	line_temp = condition->line;
	if (!(condition->line = (char*)malloc(sizeof(char) * total_len)))
		return (ERROR);
	idx = 0;
	word_idx = 0;
	while (idx < condition->line_len + word_len)
	{
		if (idx < condition->line_len)
			condition->line[idx] = line_temp[idx];
		else if (idx >= condition->line_len)
		{
			condition->line[idx] = word[word_idx];
			word_idx++;
		}
		idx++;
	}
	condition->line_len = idx;
	free(line_temp);
	return (SUCCESS);
}
