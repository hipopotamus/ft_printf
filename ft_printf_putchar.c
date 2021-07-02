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
	char word_temp[2];

	word_temp[0] = *(condition->format);
	word_temp[1] = '\0';
	ft_extend_line(&(condition->line), word_temp, 
			ft_strlen(condition->line) + 1);
	condition->format++;
	return (1);
}
