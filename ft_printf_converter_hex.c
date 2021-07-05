/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_hex.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:44:00 by sungwopa          #+#    #+#             */
/*   Updated: 2021/07/05 21:13:11 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	adjust_flag(t_printf_flag *f)
{
	if (f->minus || f->precision_exist)
		f->zero = 0;
}

static int	set_content(va_list ap, t_printf_flag *f, t_printf_content *pc)
{
	unsigned int	n;
	char			*base;

	n = va_arg(ap, unsigned int);
	if (f->specifier == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (f->precision_exist && f->precision == 0 && n == 0)
		pc->content = ft_strdup("");
	else
		pc->content = ft_uitoa_base(n, base);
	if (pc->content == NULL)
		return (ERROR);
	pc->content_len = ft_strlen(pc->content);
	pc->must_content_len = ft_sizet_max(f->precision, pc->content_len);
	return (SUCCESS);
}

static int	set_res(t_printf_flag *f, t_printf_res *r, t_printf_content *pc)
{
	size_t	idx;

	r->res_len = ft_sizet_max(f->width, pc->must_content_len);
	r->res = (char *)malloc(sizeof(char) * r->res_len);
	if (!r->res)
		return (ERROR);
	if (f->zero)
	{
		ft_memset(r->res, '0', r->res_len);
		idx = r->res_len - pc->content_len;
	}
	else
	{
		ft_memset(r->res, ' ', r->res_len);
		idx = ft_tenary(f->minus, 0, r->res_len - pc->must_content_len);
		ft_memset(&r->res[idx], '0', pc->must_content_len);
		idx = idx + pc->must_content_len - pc->content_len;
	}
	ft_memcpy(&r->res[idx], pc->content, pc->content_len);
	return (SUCCESS);
}

int	ft_printf_converter_hex(
								va_list ap, t_printf_flag *f, t_printf_res *r)
{
	t_printf_content	pc;

	adjust_flag(f);
	if (set_content(ap, f, &pc) == ERROR)
		return (ERROR);
	if (set_res(f, r, &pc) == ERROR)
		return (ERROR);
	free(pc.content);
	return (SUCCESS);
}
