/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_specifier.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:45:17 by sungwopa          #+#    #+#             */
/*   Updated: 2021/07/05 21:33:33 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_printf_get_specifier(const char *format, const char *specifiers)
{
	size_t	idx;

	idx = 1;
	while (format[idx])
	{
		if (ft_isinset(format[idx], specifiers))
			break ;
		idx++;
	}
	return (format[idx]);
}
