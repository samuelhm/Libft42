/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:31:43 by shurtado          #+#    #+#             */
/*   Updated: 2024/01/11 19:19:49 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;

	sign = 0;
	num = 0;
	while (*str <= 32 && *str != 27)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign = 1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	if (sign > 0)
		num = -num;
	return (num);
}
