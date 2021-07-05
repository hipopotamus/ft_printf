/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_int.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:44:12 by sungwopa          #+#    #+#             */
/*   Updated: 2021/07/05 21:19:31 by sungwopa         ###   ########.fr       */
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
	long	n;

	n = va_arg(ap, int);
	if (n < 0)
		pc->prefix = ft_strdup("-");
	else
		pc->prefix = ft_strdup("");
	if (pc->prefix == NULL)
		return (ERROR);
	pc->prefix_len = ft_strlen(pc->prefix);
	if (f->precision_exist && f->precision == 0 && n == 0)
		pc->content = ft_strdup("");
	else
		pc->content = ft_uitoa(ft_tenary((n >= 0), n, n * -1));
	if (pc->content == NULL)
		return (ERROR);
	pc->content_len = ft_strlen(pc->content);
	pc->must_content_len = ft_sizet_max(f->precision, pc->content_len);
	return (SUCCESS);
}

static int	set_res(t_printf_flag *f, t_printf_res *r, t_printf_content *pc)
{
	size_t	idx;

	r->res_len = ft_sizet_max(f->width, pc->prefix_len + pc->must_content_len);
	r->res = (char *)malloc(sizeof(char) * r->res_len);
	if (!r->res)
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
		idx = ft_tenary(f->minus, pc->prefix_len,
				r->res_len - pc->must_content_len);
		ft_memcpy(&r->res[idx - pc->prefix_len], pc->prefix, pc->prefix_len);
		ft_memset(&r->res[idx], '0', pc->must_content_len);
		idx = idx + pc->must_content_len - pc->content_len;
	}
	ft_memcpy(&r->res[idx], pc->content, pc->content_len);
	return (SUCCESS);
}

int	ft_printf_converter_int(
								va_list ap, t_printf_flag *f, t_printf_res *r)
{
	t_printf_content	pc;

	adjust_flag(f);
	if (set_content(ap, f, &pc) == ERROR)
		return (ERROR);
	if (set_res(f, r, &pc) == ERROR)
		return (ERROR);
	free(pc.prefix);
	free(pc.content);
	return (SUCCESS);
}
