/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:16:36 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/18 20:18:31 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_2d_array(void **v)
{
	int	i;

	i = 0;
	if (!v)
		return ;
	while (v[i] != NULL)
	{
		free(v[i]);
		i++;
	}
	free(v);
}
