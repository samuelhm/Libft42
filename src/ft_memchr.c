/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:32:11 by shurtado          #+#    #+#             */
/*   Updated: 2024/07/02 19:51:59 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned int	i;

	i = 0;
	p = (unsigned char *) s;
	while (i < n)
	{
		if (p[i] == (unsigned char) c)
			return ((void *) p + i);
		i++;
	}
	return (0);
}
