/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_string.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:15:39 by kycho             #+#    #+#             */
/*   Updated: 2020/04/10 21:34:15 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		adjust_flag(t_printf_flag *f)
{
	if (f->minus)
		f->zero = 0;
}

static void		set_content(va_list ap, t_printf_flag *f, t_printf_content *pc)
{
	pc->content = va_arg(ap, char *);
	if (pc->content == NULL)
		pc->content = "(null)";
	if (f->precision_exist)
		pc->content_len = ft_sizet_min(f->precision, ft_strlen(pc->content));
	else
		pc->content_len = ft_strlen(pc->content);
}

static int		set_res(t_printf_flag *f, t_printf_res *r, t_printf_content *pc)
{
	size_t idx;

	r->res_len = ft_sizet_max(f->width, pc->content_len);
	if (!(r->res = (char *)malloc(sizeof(char) * r->res_len)))
		return (ERROR);
	if (f->zero)
		ft_memset(r->res, '0', r->res_len);
	else
		ft_memset(r->res, ' ', r->res_len);
	idx = (f->minus) ? 0 : r->res_len - pc->content_len;
	ft_memcpy(&r->res[idx], pc->content, pc->content_len);
	return (SUCCESS);
}

int				ft_printf_converter_string(
								va_list ap, t_printf_flag *f, t_printf_res *r)
{
	t_printf_content pc;

	adjust_flag(f);
	set_content(ap, f, &pc);
	if (set_res(f, r, &pc) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
