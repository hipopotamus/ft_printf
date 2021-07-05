/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_handler.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:43:15 by sungwopa          #+#    #+#             */
/*   Updated: 2021/07/05 21:09:16 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_conversion_len(const char *format, char specifier)
{
	size_t	len;

	len = 1;
	while (format[len] != specifier)
		len++;
	return (len + 1);
}

void	*get_converter(char specifier)
{
	if (specifier == 'c')
		return (&ft_printf_converter_char);
	else if (specifier == 's')
		return (&ft_printf_converter_string);
	else if (specifier == 'p')
		return (&ft_printf_converter_pointer);
	else if (specifier == 'd' || specifier == 'i')
		return (&ft_printf_converter_int);
	else if (specifier == 'u')
		return (&ft_printf_converter_unsigned_int);
	else if (specifier == 'x' || specifier == 'X')
		return (&ft_printf_converter_hex);
	else if (specifier == '%')
		return (&ft_printf_converter_percent);
	return (NULL);
}

int	ft_printf_conversion_handler(
							t_printf_condition *condition, char *specifiers)
{
	char			specifier;
	t_printf_flag	flag;
	t_printf_res	result;
	t_converter		converter;

	specifier = ft_printf_get_specifier(condition->format, specifiers);
	if (!specifier)
		return (ERROR);
	if (ft_printf_set_flag(&flag, condition, specifier) == ERROR)
		return (ERROR);
	converter = get_converter(specifier);
	if (!converter)
		return (ERROR);
	if (converter(condition->ap, &flag, &result) == ERROR)
		return (ERROR);
	if (!(ft_printf_getbuffer(condition, result.res, result.res_len)))
		return (ERROR);
	condition->format += get_conversion_len(condition->format, specifier);
	free(result.res);
	return (result.res_len);
}
