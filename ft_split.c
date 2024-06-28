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

char	*get_first_word(char const *s, char c)
{
	char	*tmp;
	char	*del2;

	tmp = ft_strdup(s);
	del2 = ft_strchr(tmp, c);
	*del2 = 0;
	return (tmp);
}

char	**not_found(char const *s)
{
	char	**arr;

	arr = malloc(sizeof(char *) * 2);
	if (!arr)
		return (NULL);
	arr[0] = ft_strdup(s);
	if (!arr[0])
	{
		free(arr);
		return (NULL);
	}
	arr[1] = NULL;
	return (arr);
}

char	**found(char const *s, char *del)
{
	char	**arr;

	arr = malloc(sizeof(char *) * 3);
	if (!arr)
		return (NULL);
	arr[0] = get_first_word(s, *del);
	if (!arr[0])
	{
		free(arr);
		return (NULL);
	}
	arr[1] = ft_strdup(del + 1);
	if (!arr[1])
	{
		free(arr[0]);
		free(arr);
		return (NULL);
	}
	arr[2] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	*del;

	if (!s)
		return (NULL);
	del = ft_strchr(s, c);
	if (!del)
		return (not_found(s));
	else
		return (found(s, del));
}
