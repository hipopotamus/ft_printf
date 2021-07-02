#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

# define FT_PRINTF_TARGET '%'
# define FT_PRINTF_SPECIFIERS "cspdiuxX%"
# define FT_PRINTF_FD STDOUT
# define ERROR -1
# define SUCCESS 1

typedef struct	s_printf_condition
{
	const char	*format;
	va_list		ap;
	int			fd;
	char		*line;
	size_t		line_idx;
	size_t		line_len;
}				t_printf_condition;

typedef struct	s_printf_flag
{
	char		specifier;
	int			space;
	int			zero;
	int			minus;
	size_t		width;
	int			precision_exist;
	size_t		precision;
}				t_printf_flag;

typedef struct	s_printf_content
{
	char		*prefix;
	size_t		prefix_len;
	char		*content;
	size_t		content_len;
	size_t		must_content_len;
}				t_printf_content;

typedef struct	s_printf_res
{
	char		*res;
	size_t		res_len;
}				t_printf_res;

typedef int		(*t_converter)(va_list, t_printf_flag *, t_printf_res *);

int				ft_printf(const char *format, ...);
int				ft_printf_putchar(t_printf_condition *condition);
int				ft_printf_conversion_handler
					(t_printf_condition *condition, char *specifiers);
char			ft_printf_get_specifier
					(const char *format, const char *specifiers);
int				ft_printf_set_flag
					(t_printf_flag *f, t_printf_condition *c, char specifier);

int				ft_printf_converter_char
							(va_list ap, t_printf_flag *f, t_printf_res *r);
int				ft_printf_converter_string
							(va_list ap, t_printf_flag *f, t_printf_res *r);
int				ft_printf_converter_pointer
							(va_list ap, t_printf_flag *f, t_printf_res *r);
int				ft_printf_converter_int
							(va_list ap, t_printf_flag *f, t_printf_res *r);
int				ft_printf_converter_unsigned_int
							(va_list ap, t_printf_flag *f, t_printf_res *r);
int				ft_printf_converter_hex
							(va_list ap, t_printf_flag *f, t_printf_res *r);
int				ft_printf_converter_percent
							(va_list ap, t_printf_flag *f, t_printf_res *r);
int				ft_printf_getbuffer(t_printf_condition *condition, 
				const char *word, size_t word_len);
#endif
