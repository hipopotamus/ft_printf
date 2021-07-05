/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set_flag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:48:33 by sungwopa          #+#    #+#             */
/*   Updated: 2021/07/05 21:42:15 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flag(t_printf_flag *flag, char specifier)
{
	flag->specifier = specifier;
	flag->zero = 0;
	flag->minus = 0;
	flag->width = 0;
	flag->precision_exist = 0;
	flag->precision = 0;
}

void	set_front_flag(t_printf_flag *f, t_printf_condition *c, size_t *idx)
{
	const char	*format;

	format = c->format;
	while (format[*idx] == '-' || format[*idx] == '0')
	{
		if (format[*idx] == '0')
			f->zero = 1;
		if (format[*idx] == '-')
			f->minus = 1;
		(*idx)++;
	}
}

void	set_width_flag(t_printf_flag *f, t_printf_condition *c, size_t *idx)
{
	const char	*format;
	long		tmp;

	format = c->format;
	if (format[*idx] == '*')
	{
		tmp = va_arg(c->ap, int);
		if (tmp < 0)
		{
			f->minus = 1;
			tmp *= -1;
		}
		f->width = tmp;
		(*idx)++;
	}
	else
	{
		f->width = ft_atoi(&format[*idx]);
		while (ft_isdigit(format[*idx]))
			(*idx)++;
	}
}

void	set_precision_flag(t_printf_flag *f, t_printf_condition *c, size_t *idx)
{
	const char	*format;
	long		tmp;

	format = c->format;
	if (format[*idx] == '.')
	{
		(*idx)++;
		f->precision_exist = 1;
		if (format[*idx] == '*')
		{
			tmp = va_arg(c->ap, int);
			if (tmp < 0)
				f->precision_exist = 0;
			else
				f->precision = tmp;
			(*idx)++;
		}
		else
		{
			f->precision = ft_atoi(&format[*idx]);
			while (ft_isdigit(format[*idx]))
				(*idx)++;
		}
	}
}

int	ft_printf_set_flag(
					t_printf_flag *f, t_printf_condition *c, char specifier)
{
	size_t	idx;

	idx = 1;
	init_flag(f, specifier);
	set_front_flag(f, c, &idx);
	set_width_flag(f, c, &idx);
	set_precision_flag(f, c, &idx);
	if ((c->format)[idx] != specifier)
		return (ERROR);
	return (SUCCESS);
}
