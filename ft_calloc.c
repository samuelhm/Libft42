/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:12:40 by shurtado          #+#    #+#             */
/*   Updated: 2024/01/12 13:01:42 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(unsigned int num, size_t size)
{
	unsigned int	i;
	unsigned char	*p;

	if (size != 0 && num > (unsigned int)(-1) / size)
		return (0);
	i = 0;
	p = malloc(num * size);
	if (!p)
		return (0);
	while (i < num * size)
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}
