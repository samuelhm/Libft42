/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:32:19 by shurtado          #+#    #+#             */
/*   Updated: 2024/01/11 19:20:50 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*pdest;
	unsigned char	*psrc;

	pdest = (unsigned char *) dest;
	psrc = (unsigned char *) src;
	if (psrc < pdest)
	{
		i = n - 1;
		while (i >= 0)
		{
			pdest[i] = psrc[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while ((unsigned int) i < n)
		{
			pdest[i] = psrc[i];
			i++;
		}
	}
	return (dest);
}
