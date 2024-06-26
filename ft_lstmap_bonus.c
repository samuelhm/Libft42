/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:08:37 by shurtado          #+#    #+#             */
/*   Updated: 2024/06/26 18:41:39 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void* (*f)(void *), void (*del)(void *))
{
	t_list	*newlist;

	if (!lst || !f || !del)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		if (!newlist)
			newlist = ft_lstnew(f(lst->content));
		else
			ft_lstadd_back(&lst, ft_lstnew(f(lst->content)));
	}
	return (newlist);
}
