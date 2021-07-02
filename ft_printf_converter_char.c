#include "ft_printf.h"

static void		adjust_flag(t_printf_flag *f)
{
	if (f->minus)
		f->zero = 0;
}

static int		set_res(t_printf_flag *f, t_printf_res *r, va_list ap)
{
	size_t idx;

	r->res_len = ft_sizet_max(f->width, 1);
	if (!(r->res = (char *)malloc(sizeof(char) * r->res_len)))
		return (ERROR);
	if (f->zero)
		ft_memset(r->res, '0', r->res_len);
	else
		ft_memset(r->res, ' ', r->res_len);
	idx = (f->minus) ? 0 : r->res_len - 1;
	if (va_arg(ap,int) != 0)
		r->res[idx] = va_arg(ap, int);
	return (SUCCESS);
}

int				ft_printf_converter_char(
								va_list ap, t_printf_flag *f, t_printf_res *r)
{
	adjust_flag(f);
	if (set_res(f, r, ap) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
