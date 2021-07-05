/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:39:06 by sungwopa          #+#    #+#             */
/*   Updated: 2021/07/05 22:06:07 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_n_len(unsigned int n, size_t base_len)
{
	int	n_len;

	if (n == 0)
		return (1);
	n_len = 0;
	while (n != 0)
	{
		n /= base_len;
		n_len++;
	}
	return (n_len);
}

char	*ft_uitoa_base(unsigned int n, const char *base)
{
	char	*res;
	int		n_len;
	size_t	base_len;

	base_len = ft_strlen(base);
	n_len = get_n_len(n, base_len);
	res = (char *)malloc(sizeof(char) * (n_len + 1));
	if (res == NULL)
		return (NULL);
	res[n_len] = '\0';
	res[0] = '0';
	n_len--;
	while (n != 0)
	{
		res[n_len] = base[n % base_len];
		n /= base_len;
		n_len--;
	}
	return (res);
}
