/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:11:44 by shurtado          #+#    #+#             */
/*   Updated: 2024/06/24 22:13:41 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (ft_strchr(set, *(s1 + i)) && *s1)
		i++;
	while (j > 0 && ft_strchr(set, *(s1 + j)))
		j--;
	if (j == 0)
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (j - i + 2));
	if (!str)
		return (NULL);
	ft_strlcpy(str, (s1 + i), j - i + 2);
	return (str);
}
