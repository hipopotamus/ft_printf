/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_pointer.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 15:09:54 by kycho             #+#    #+#             */
/*   Updated: 2020/04/10 21:05:34 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		adjust_flag(t_printf_flag *f)
{
	if (f->minus || f->precision_exist)
		f->zero = 0;
}

static int		set_content(va_list ap, t_printf_flag *f, t_printf_content *pc)
{
	void			*p;
	char			*base;

	p = va_arg(ap, void *);
	base = "0123456789abcdef";
	if (!(pc->prefix = ft_strdup("0x")))
		return (ERROR);
	pc->prefix_len = ft_strlen(pc->prefix);
	if (f->precision_exist && f->precision == 0 && p == NULL)
		pc->content = ft_strdup("");
	else
		pc->content = ft_ultoa_base((size_t)p, base);
	if (pc->content == NULL)
		return (ERROR);
	pc->content_len = ft_strlen(pc->content);
	pc->must_content_len = ft_sizet_max(f->precision, pc->content_len);
	return (SUCCESS);
}

static int		set_res(t_printf_flag *f, t_printf_res *r, t_printf_content *pc)
{
	size_t idx;

	r->res_len = ft_sizet_max(f->width, pc->prefix_len + pc->must_content_len);
	if (!(r->res = (char *)malloc(sizeof(char) * r->res_len)))
		return (ERROR);
	if (f->zero)
	{
		ft_memset(r->res, '0', r->res_len);
		ft_memcpy(&r->res[0], pc->prefix, pc->prefix_len);
		idx = r->res_len - pc->content_len;
	}
	else
	{
		ft_memset(r->res, ' ', r->res_len);
		idx = (f->minus) ? pc->prefix_len : r->res_len - pc->must_content_len;
		ft_memcpy(&r->res[idx - pc->prefix_len], pc->prefix, pc->prefix_len);
		ft_memset(&r->res[idx], '0', pc->must_content_len);
		idx = idx + pc->must_content_len - pc->content_len;
	}
	ft_memcpy(&r->res[idx], pc->content, pc->content_len);
	return (SUCCESS);
}

int				ft_printf_converter_pointer(
								va_list ap, t_printf_flag *f, t_printf_res *r)
{
	t_printf_content pc;

	adjust_flag(f);
	if (set_content(ap, f, &pc) == ERROR)
		return (ERROR);
	if (set_res(f, r, &pc) == ERROR)
		return (ERROR);
	free(pc.prefix);
	free(pc.content);
	return (SUCCESS);
}
