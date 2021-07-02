/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:59:02 by sungwopa          #+#    #+#             */
/*   Updated: 2021/05/08 21:00:19 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	len_s;
	char	*sub;

	len_s = ft_strlen(s);
	size = 0;
	if (len_s > start)
	{
		if (len_s - start < len)
			size = len_s - start;
		else
			size = len;
	}
	sub = malloc((size + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, s + start, size + 1);
	return (sub);
}
