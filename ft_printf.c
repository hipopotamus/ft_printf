/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:11 by sungwopa          #+#    #+#             */
/*   Updated: 2021/07/05 20:34:05 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	init_ft_printf(const char **format, int *total_written,
		t_printf_condition *condition, char **specifiers)
{
	if (*format == NULL)
		return (ERROR);
	*total_written = 0;
	*specifiers = FT_PRINTF_SPECIFIERS;
	condition->format = *format;
	condition->fd = FT_PRINTF_FD;
	condition->line = (char *)malloc(sizeof(char) * 1);
	ft_memset(condition->line, 0, 1);
	condition->line_len = 0;
	return (SUCCESS);
}

int	ft_printf(const char *format, ...)
{
	int					total_written;
	int					written;
	char				*specifiers;
	t_printf_condition	condition;

	if (!(init_ft_printf(&format, &total_written, &condition, &specifiers)))
		return (ERROR);
	va_start(condition.ap, format);
	while (*condition.format != '\0')
	{
		if (*condition.format == FT_PRINTF_TARGET)
			written = ft_printf_conversion_handler(&condition, specifiers);
		else
		{
			written = ft_printf_putchar(&condition);
		}
		if (written == ERROR)
			return (ERROR);
		total_written += written;
	}
	va_end(condition.ap);
	write(1, condition.line, condition.line_len);
	free(condition.line);
	return (total_written);
}
