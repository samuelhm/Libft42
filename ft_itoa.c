/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:12:23 by shurtado          #+#    #+#             */
/*   Updated: 2024/06/25 00:19:12 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	getsize(int n);

char	*ft_itoa(int n)
{
	char	*txtnumber;
	int		len;
	int		sign;

	if (n < 0)
		sign = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = getsize(n);
	txtnumber = malloc(sizeof(char) * (len + 1));
	if (!txtnumber)
		return (NULL);
	txtnumber[len] = 0;
	while (len > 0)
	{
		txtnumber[--len] = (n % 10) + '0';
		n /= 10;
	}
	if (sign)
		txtnumber[0] = '-';
	return (txtnumber);
}

int	getsize(int n)
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
