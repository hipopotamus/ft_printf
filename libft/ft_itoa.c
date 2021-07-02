/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:09:22 by sungwopa          #+#    #+#             */
/*   Updated: 2021/05/10 15:11:09 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_int(long n)
{
	size_t cnt;

	cnt = 0;
	if (n < 0)
	{
		cnt++;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		cnt++;
		n = n / 10;
	}
	return (cnt);
}

static char		*int_to_a(char *ptr, long n, size_t len)
{
	size_t i;

	ptr[len] = '\0';
	if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
	}
	if (n == 0)
	{
		ptr[0] = '0';
		return (ptr);
	}
	i = len - 1;
	while (n > 0)
	{
		ptr[i] = '0' + n % 10;
		n = n / 10;
		i--;
	}
	return (ptr);
}

char			*ft_itoa(int n)
{
	size_t		len;
	char		*ptr;
	long		dum_n;

	dum_n = n;
	len = len_int(dum_n);
	ptr = (char*)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	return (int_to_a(ptr, n, len));
}
