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
	unsigned char	*pdest;
	unsigned char	*psrc;

	pdest = (unsigned char *) dest;
	psrc = (unsigned char *) src;
	if (n == 0 || dest == src)
		return (dest);
	if (psrc < pdest)
	{
		while (n--)
			pdest[n] = psrc[n];
	}
	else
		ft_memcpy(pdest, psrc, n);
	return (dest);
}
