/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:12:00 by shurtado          #+#    #+#             */
/*   Updated: 2024/06/25 00:51:37 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	assign(int *size, char **arr, char *split, char const *s);

char	**freall(char **arr)
{
	free(arr[0]);
	free(arr[1]);
	free(arr);
	return (NULL);
}

void	cpy(char **arr, int *size, char const *s, char *split)
{
	ft_strlcpy(arr[0], s, size[0]);
	ft_strlcpy(arr[1], split + 1, size[1]);
	arr[2] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	*split;
	int		size[2];

	if (!s)
		return (NULL);
	split = ft_strchr(s, c);
	if (!split)
	{
		arr = malloc(sizeof(char *) * 2);
		if (!arr)
			return (NULL);
		arr[0] = ft_strdup(s);
		arr[1] = NULL;
		return (arr);
	}
	arr = malloc (sizeof(char *) * 3);
	if (!arr)
		return (NULL);
	assign(size, arr, split, s);
	if (!arr[0] || !arr[1])
		return (freall(arr));
	cpy(arr, size, s, split);
	return (arr);
}

void	assign(int *size, char **arr, char *split, char const *s)
{
	size[1] = ft_strlen(split + 1) + 1;
	size[0] = ((ft_strlen(s) + 1) - size[1]);
	arr[0] = malloc (sizeof(char) * size[0]);
	arr[1] = malloc (sizeof(char) * size[1]);
}
