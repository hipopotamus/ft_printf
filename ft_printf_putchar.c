/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:47:47 by sungwopa          #+#    #+#             */
/*   Updated: 2021/07/05 14:48:24 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putchar(t_printf_condition *condition)
{
	char word_temp[1];

	word_temp[0] = *(condition->format);
	ft_printf_getbuffer(condition, word_temp, 1);
	condition->format++;
	return (SUCCESS);
}
