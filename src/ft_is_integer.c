/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:09:54 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/24 19:04:02 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_integer(const char *str, int negative);

int	ft_is_integer(const char *str)
{
	int	negative;
	int	i;

	negative = 0;
	if (!str)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = 1;
		str++;
	}
	if (*str == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (ft_strlen(str) < 10 || check_integer(str, negative));
}

static int	check_integer(const char *str, int negative)
{
	const char	*max_str;

	if (ft_strlen(str) > 10)
		return (0);
	if (negative)
		max_str = "2147483648";
	else
		max_str = "2147483647";
	if (ft_strncmp(str, max_str, 10) > 0)
		return (0);
	else
		return (1);
}
