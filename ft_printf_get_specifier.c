/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_specifier.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 21:30:48 by kycho             #+#    #+#             */
/*   Updated: 2020/04/10 21:31:14 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_printf_get_specifier(const char *format, const char *specifiers)
{
	size_t idx;

	idx = 1;
	while (format[idx])
	{
		if (ft_isinset(format[idx], specifiers))
			break ;
		idx++;
	}
	return (format[idx]);
}
