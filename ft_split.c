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

int		get_total_deli(char const *s, char c);
void	alloc(char **arr, char const *s, char c, int deli);
char	*get_word(char const *s, int pos, char c, int i);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		delimiter;

	if (!s || !c)
		return (NULL);
	delimiter = get_total_deli(s, c);
	arr = malloc((delimiter + 2) * sizeof(char *));
	alloc(arr, s, c, delimiter);
	return (arr);
}

int	get_total_deli(char const *s, char c)
{
	int	result;

	result = 0;
	while (*s)
	{
		if (*s == c)
			result++;
		s++;
	}
	return (result);
}

char	*get_word(char const *s, int pos, char c, int i)
{
	int	num;
	int	start;
	int	word;

	num = 0;
	start = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			num++;
			if (num == pos)
				return (ft_substr(s, start, word));
			start = i + 1;
			word = 0;
		}
		else
			word++;
		i++;
	}
	if (num + 1 == pos)
		return (ft_substr(s, start, word));
	return (NULL);
}

void	alloc(char **arr, char const *s, char c, int deli)
{
	int	i;

	i = 0;
	while (i <= deli)
	{
		arr[i] = get_word(s, i + 1, c, 0);
		i++;
	}
	arr[i] = NULL;
}
