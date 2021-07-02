/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:30:40 by sungwopa          #+#    #+#             */
/*   Updated: 2021/05/10 17:38:00 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *nxt;
	t_list *src;

	if (!lst || !del || !*lst)
		return ;
	src = *lst;
	while (src != NULL)
	{
		nxt = src->next;
		ft_lstdelone(src, del);
		src = nxt;
	}
	*lst = NULL;
}
