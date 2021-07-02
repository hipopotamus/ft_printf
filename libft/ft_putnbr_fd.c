/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:05:29 by sungwopa          #+#    #+#             */
/*   Updated: 2021/05/10 15:47:58 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long nl;

	nl = (long)n;
	if (nl < 0)
	{
		ft_putchar_fd('-', fd);
		nl *= -1;
	}
	if (nl < 10)
	{
		ft_putchar_fd('0' + nl, fd);
		return ;
	}
	ft_putnbr_fd(nl / 10, fd);
	ft_putchar_fd(('0' + nl % 10), fd);
}
