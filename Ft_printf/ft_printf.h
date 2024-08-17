/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:13:29 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/17 11:40:26 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putcharp(int c);
int	ft_putstrp(const char *str);
int	ft_putnbrp(int nb);
int	ft_putunbrp(unsigned int nb);
int	ft_puthxnbrp(unsigned int nb, int upper);
int	ft_putptrp(unsigned long nb);

#endif
