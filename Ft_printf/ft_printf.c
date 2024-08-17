/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:13:51 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/17 11:39:44 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printarg(char carg, va_list args);

int	ft_printf(char const *str, ...)
{
	int		i;
	va_list	args;
	int		result;

	va_start(args, str);
	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] == '%')
			result += printarg(str[++i], args);
		else
		{
			write(1, &str[i], 1);
			result++;
		}
		i++;
	}
	va_end(args);
	return (result);
}

int	printarg(char carg, va_list args)
{
	unsigned long	p;

	if (carg == 'c')
		return (ft_putcharp(va_arg(args, int)));
	else if (carg == 's')
		return (ft_putstrp(va_arg(args, const char *)));
	else if (carg == 'd' || carg == 'i')
		return (ft_putnbrp(va_arg(args, int)));
	else if (carg == 'u')
		return (ft_putunbrp(va_arg(args, unsigned int)));
	else if (carg == 'x')
		return (ft_puthxnbrp(va_arg(args, unsigned int), 1));
	else if (carg == 'X')
		return (ft_puthxnbrp(va_arg(args, unsigned int), 0));
	else if (carg == 'p')
	{
		p = va_arg(args, unsigned long);
		if (p)
			return (write(1, "0x", 2) + ft_putptrp(p));
		else
			return (write(1, "(nil)", 5));
	}
	else
		return (write(1, &carg, 1));
}
