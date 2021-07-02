/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:47:01 by sungwopa          #+#    #+#             */
/*   Updated: 2021/05/10 16:31:01 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *find, size_t len)
{
	size_t i;
	size_t len_find;
	size_t len_src;

	len_find = ft_strlen(find);
	len_src = ft_strlen(src);
	i = 0;
	if (len_find == 0)
		return ((char*)src);
	if (len > len_src)
		len = len_src;
	while (i + len_find <= len)
	{
		if (ft_strncmp(src + i, find, len_find) == 0)
		{
			return ((char*)src + i);
		}
		i++;
	}
	return (NULL);
}
