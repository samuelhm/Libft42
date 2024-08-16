/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 08:23:58 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/09 11:02:30 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *str)
{
	int	i;

	if (!str)
		return (ft_putstr("(null)"));
	i = 0;
	while (str[i])
		i++;
	return (write(1, str, i));
}

int	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		return (write(1, "-", 1) + ft_putnbr(nb * -1));
	}
	if (nb >= 10)
	{
		return (ft_putnbr(nb / 10) + ft_putnbr(nb % 10));
	}
	else
	{
		return (ft_putchar(nb + 48));
	}
}

int	ft_putunbr(unsigned int nb)
{
	int	result;

	result = 0;
	if (nb >= 10)
		result += ft_putunbr(nb / 10);
	result += (ft_putchar((nb % 10) + 48));
	return (result);
}
