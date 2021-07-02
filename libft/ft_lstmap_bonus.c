/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:43:23 by sungwopa          #+#    #+#             */
/*   Updated: 2021/05/10 19:00:58 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*first_new_lst;
	t_list	*new_lst;

	if (!lst || !f || !del)
		return (NULL);
	if (!(first_new_lst = ft_lstnew(f(lst->content))))
		return (NULL);
	new_lst = first_new_lst;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (!(new_lst->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&first_new_lst, del);
			return (NULL);
		}
		new_lst = new_lst->next;
	}
	return (first_new_lst);
}
