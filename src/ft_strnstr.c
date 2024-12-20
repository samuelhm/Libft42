/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:32:40 by shurtado          #+#    #+#             */
/*   Updated: 2024/10/26 17:58:21 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	if (!n && needle[0] == '\0')
		return ((char *) haystack);
	else if (!n)
		return (NULL);
	i = 0;
	if (!*needle)
		return ((char *) haystack);
	while (haystack[i] && i < n)
	{
		j = 0;
		while (needle[j] == haystack[j + i] && (i + j < n))
		{
			j++;
			if (needle[j] == 0)
				return ((char *) haystack + i);
		}
		i++;
	}
	return (0);
}
