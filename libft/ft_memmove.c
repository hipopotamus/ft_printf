/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:34:51 by sungwopa          #+#    #+#             */
/*   Updated: 2021/05/08 21:29:41 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst <= src)
	{
		ft_memcpy(dst, src, len);
		return (dst);
	}
	while (len > 0)
	{
		len--;
		((unsigned char*)dst)[len] = ((unsigned char*)src)[len];
	}
	return (dst);
}
