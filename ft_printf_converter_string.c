/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_string.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:44:52 by sungwopa          #+#    #+#             */
/*   Updated: 2021/07/05 21:30:25 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	adjust_flag(t_printf_flag *f)
{
	if (f->minus)
		f->zero = 0;
}

static void	set_content(va_list ap, t_printf_flag *f, t_printf_content *pc)
{
	pc->content = va_arg(ap, char *);
	if (pc->content == NULL)
		pc->content = "(null)";
	if (f->precision_exist)
		pc->content_len = ft_sizet_min(f->precision, ft_strlen(pc->content));
	else
		pc->content_len = ft_strlen(pc->content);
}

static int	set_res(t_printf_flag *f, t_printf_res *r, t_printf_content *pc)
{
	size_t	idx;

	r->res_len = ft_sizet_max(f->width, pc->content_len);
	r->res = (char *)malloc(sizeof(char) * r->res_len);
	if (!r->res)
		return (ERROR);
	if (f->zero)
		ft_memset(r->res, '0', r->res_len);
	else
		ft_memset(r->res, ' ', r->res_len);
	idx = ft_tenary(f->minus, 0, r->res_len - pc->content_len);
	ft_memcpy(&r->res[idx], pc->content, pc->content_len);
	return (SUCCESS);
}

int	ft_printf_converter_string(
								va_list ap, t_printf_flag *f, t_printf_res *r)
{
	t_printf_content	pc;

	adjust_flag(f);
	set_content(ap, f, &pc);
	if (set_res(f, r, &pc) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
