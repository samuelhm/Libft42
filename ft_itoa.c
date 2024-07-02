/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:12:23 by shurtado          #+#    #+#             */
/*   Updated: 2024/07/02 19:44:02 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getsizen(int n);

char	*ft_itoa(int n)
{
	char	*txtnumber;
	int		len;
	int		sign;
	long	num;

	num = n;
	sign = 0;
	if (n < 0)
		sign = 1;
	len = getsizen(n);
	txtnumber = malloc(sizeof(char) * (len + 1));
	if (!txtnumber)
		return (NULL);
	txtnumber[len] = '\0';
	if (sign)
		num = -num;
	while (len > 0)
	{
		txtnumber[--len] = (num % 10) + '0';
		num /= 10;
	}
	if (sign)
		txtnumber[0] = '-';
	return (txtnumber);
}

int	getsizen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}
