/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:32:28 by shurtado          #+#    #+#             */
/*   Updated: 2024/01/11 19:07:50 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, const char *src, size_t n)
{
	unsigned int	dslen;
	unsigned int	srlen;
	unsigned int	i;

	dslen = ft_strlen(dest);
	srlen = ft_strlen(src);
	i = 0;
	if (dslen >= n)
		return (n + srlen);
	while (src[i] != 0 && dslen + i < n - 1)
	{
		dest[dslen + i] = src[i];
		i++;
	}
	dest[dslen + i] = 0;
	return (dslen + srlen);
}
