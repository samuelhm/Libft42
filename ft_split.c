/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:12:00 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/16 14:03:18 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_total_deli(char const *s, char c);
static void	alloc(char **arr, char const *s, char c, int deli);
static char	*get_word(char const *s, int pos, char c, int i);
static char	*clean(char const *s, char del, int i, int j);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		delimiter;
	char	*sclean;

	if (!s)
		return (NULL);
	sclean = clean(s, c, 0, 0);
	delimiter = get_total_deli(sclean, c);
	if (*sclean == c || *sclean == '\0')
	{
		arr = malloc(sizeof(char *));
		arr[0] = NULL;
		free(sclean);
		return (arr);
	}
	arr = malloc((delimiter + 2) * sizeof(char *));
	if (!arr)
		return (NULL);
	alloc(arr, sclean, c, delimiter);
	free(sclean);
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
	int	j;

	i = 0;
	j = 0;
	while (i <= deli)
	{
		arr[i] = get_word(s, i + 1, c, 0);
		if (!arr[i])
		{
			while (j < i)
			{
				free(arr[j]);
				j++;
			}
			break ;
		}
		i++;
	}
	arr[i] = NULL;
}

char	*clean(char const *s, char del, int i, int j)
{
	char	*sclean;
	int		lenght;

	lenght = ft_strlen(s);
	sclean = ft_strtrim(s, &del);
	while (i < lenght)
	{
		sclean[j++] = sclean [i++];
		if (sclean[i] == del)
		{
			sclean[j++] = sclean [i++];
			while (sclean[i] == del)
				i++;
		}
	}
	sclean[j] = '\0';
	return (sclean);
}
