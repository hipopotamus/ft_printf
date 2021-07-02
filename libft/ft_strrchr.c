/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 21:12:00 by sungwopa          #+#    #+#             */
/*   Updated: 2021/05/03 21:22:48 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;
	size_t len;

	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[len - i] == (char)c)
		{
			return ((char*)s + len - i);
		}
		i++;
	}
	return (NULL);
}
