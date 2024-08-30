/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:08:09 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/30 19:14:35 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_charjoin(char *str, char c)
{
	char	*strejoined;
	char	tmp[2];

	tmp[0] = c;
	tmp[1] = '\0';
	strejoined = ft_strjoin(str, tmp);
	free(str);
	return (strejoined);
}
