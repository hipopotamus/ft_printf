/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:52:50 by sungwopa          #+#    #+#             */
/*   Updated: 2021/05/08 20:53:39 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	len_s1;
	size_t	len_s2;
	char	*ptr;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	size = len_s1 + len_s2;
	ptr = (char*)ft_calloc((size + 1), sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, len_s1 + 1);
	ft_strlcpy(ptr + len_s1, s2, len_s2 + 1);
	return (ptr);
}
