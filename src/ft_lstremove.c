/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:11:15 by shurtado          #+#    #+#             */
/*   Updated: 2024/09/01 19:30:55 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Return 1 if node deleted, 0 if not.

int	ft_lstremove(t_list **lst, t_list *node, void (*del)(void *))
{
	t_list	*temp;
	t_list	*lstp;

	if (!lst || !(*lst) || !node)
		return (0);
	if (*lst == node)
	{
		temp = *lst;
		*lst = (*lst)->next;
		del(temp->content);
		free(temp);
		return (1);
	}
	lstp = *lst;
	while (lstp && lstp->next != node)
		lstp = lstp->next;
	if (lstp->next == node)
	{
		temp = lstp->next;
		lstp->next = temp->next;
		del(temp->content);
		free(temp);
		return (1);
	}
	return (0);
}
