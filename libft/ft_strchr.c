/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 21:03:55 by sungwopa          #+#    #+#             */
/*   Updated: 2021/05/03 21:14:33 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char*)s + i);
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char*)s + i);
	}
	return (NULL);
}
