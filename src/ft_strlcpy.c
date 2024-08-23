/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:32:31 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/18 21:39:31 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	srlen;

	i = 0;
	srlen = ft_strlen(src);
	if (n == 0)
		return (srlen);
	while ((srlen - i) && i < (n - 1) && src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (srlen);
}
