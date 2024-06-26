/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:17:54 by shurtado          #+#    #+#             */
/*   Updated: 2024/06/26 15:21:33 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(tlist **lst, t_list *new)
{
	while (*lst->next != NULL)
	{
		*lst = *lst->next;
	}
	lst->next = new;
}
