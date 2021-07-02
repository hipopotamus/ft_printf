/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:51:03 by sungwopa          #+#    #+#             */
/*   Updated: 2021/05/08 20:51:57 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*ptr;

	size = ft_strlen(s1) + 1;
	ptr = (char*)malloc((size) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, size);
	return (ptr);
}
