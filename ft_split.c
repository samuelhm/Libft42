/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:12:00 by shurtado          #+#    #+#             */
/*   Updated: 2024/06/24 22:58:58 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	*split;
	int		size1;
	int		size2;

	if (!s)
		return (NULL);
	split = ft_strchr(s, c);
	if (!split)
	{
		arr = malloc (sizeof(char *) *2);
		if (!arr)
			return (NULL);
		arr[0] = ft_strdup(s);
		arr[1] = NULL;
		return (arr);
	}
	size2 = ft_strlen(split + 1) + 1;
	size1 = ((ft_strlen(s) + 1) - size2);
	arr = malloc (sizeof(char *) * 3);
	if (!arr)
		return (NULL);
	arr[0] = malloc (sizeof(char) * size1);
	arr[1] = malloc (sizeof(char) * size2);
	if (!arr[0] || !arr[1])
	{
		free(arr[0]);
		free(arr[1]);
		free(arr);
		return (NULL);
	}
	ft_strlcpy(arr[0], s, size1);
	ft_strlcpy(arr[1], split + 1, size2);
	arr[2] = NULL;
	return (arr);
}
