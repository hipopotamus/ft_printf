#include "ft_printf.h"

int init_ft_printf(const char **format, int *total_written,
		t_printf_condition *condition, char **specifiers)
{
	if (*format == NULL)
		return (ERROR);
	*total_written = 0;
	*specifiers = FT_PRINTF_SPECIFIERS;
	condition->format = *format;
	condition->fd = FT_PRINTF_FD;
	condition->line = ft_strdup("");
	return (SUCCESS);
}

int	ft_printf(const char *format, ...)
{
	int					total_written;
	int					written;
	char				*specifiers;
	t_printf_condition	condition;

	if(!(init_ft_printf(&format, &total_written, &condition, &specifiers)))
		return (ERROR);
	va_start(condition.ap, format);
	while (*condition.format != '\0')
	{
		if (*condition.format == FT_PRINTF_TARGET)
			written = ft_printf_conversion_handler(&condition, specifiers);
		else
			written = ft_printf_putchar(&condition);
		if (written == ERROR)
			return (ERROR);
		total_written += written;
	}
	va_end(condition.ap);
	write(1, condition.line, ft_strlen(condition.line));
	free(condition.line);
	return (total_written);
}
