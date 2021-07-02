/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:13:27 by sungwopa          #+#    #+#             */
/*   Updated: 2021/05/08 21:20:09 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	return (ft_memset(ptr, 0, count * size));
}
