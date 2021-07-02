/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:03:13 by sungwopa          #+#    #+#             */
/*   Updated: 2021/05/10 17:15:24 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	cnt;
	t_list	*nxt;

	nxt = lst;
	cnt = 0;
	while (nxt != NULL)
	{
		cnt++;
		nxt = nxt->next;
	}
	return (cnt);
}
