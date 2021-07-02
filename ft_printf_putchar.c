/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 22:54:37 by kycho             #+#    #+#             */
/*   Updated: 2020/03/14 18:29:01 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putchar(t_printf_condition *condition)
{
	//ft_putchar_fd(*(condition->format), condition->fd);
	char word_temp[1];

	word_temp[0] = *(condition->format);
	ft_printf_getbuffer(condition, word_temp, 1);
	condition->format++;
	return (1);
}
