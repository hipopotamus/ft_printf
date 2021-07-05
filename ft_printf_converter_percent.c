/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_percent.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:44:26 by sungwopa          #+#    #+#             */
/*   Updated: 2021/07/05 21:22:04 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	adjust_flag(t_printf_flag *f)
{
	if (f->minus)
		f->zero = 0;
}

static int	set_res(t_printf_flag *f, t_printf_res *r)
{
	size_t	idx;

	r->res_len = ft_sizet_max(f->width, 1);
	r->res = (char *)malloc(sizeof(char) * r->res_len);
	if (!r->res)
		return (ERROR);
	if (f->zero)
		ft_memset(r->res, '0', r->res_len);
	else
		ft_memset(r->res, ' ', r->res_len);
	idx = ft_tenary(f->minus, 0, r->res_len - 1);
	r->res[idx] = '%';
	return (SUCCESS);
}

int	ft_printf_converter_percent(
					va_list ap, t_printf_flag *f, t_printf_res *r)
{
	if (f == NULL && va_arg(ap, int))
		return (ERROR);
	adjust_flag(f);
	if (set_res(f, r) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
