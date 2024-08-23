/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfill_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:33:35 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/18 18:05:36 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfill_fd(int fd)
{
	char	*buffer[3];

	buffer[0] = get_next_line(fd);
	if (!buffer[0])
		return (NULL);
	buffer[1] = get_next_line(fd);
	if (!buffer[1])
	{
		free (buffer[0]);
		return (NULL);
	}
	while (buffer[1])
	{
		buffer[2] = buffer[0];
		buffer[0] = ft_strjoin(buffer[2], buffer[1]);
		free(buffer[1]);
		free(buffer[2]);
		if (!buffer[0])
			return (NULL);
		buffer[1] = get_next_line(fd);
	}
	return (buffer[0]);
}
