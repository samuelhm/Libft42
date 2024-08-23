/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 04:55:46 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/16 12:25:24 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_line(int fd, char *buffer, char *save)
{
	char	*temp;
	int		bytes_read;

	while (!save || !ft_strchr(save, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!save)
			temp = ft_strdup(buffer);
		else
			temp = ft_strjoin(save, buffer);
		if (!temp)
		{
			free(save);
			return (NULL);
		}
		free(save);
		save = temp;
	}
	return (save);
}

static char	*get_save(char *save)
{
	char	*new_save;
	int		i;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	new_save = ft_strdup(save + i + 1);
	free(save);
	return (new_save);
}

static char	*get_line(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save[i] || !save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = ft_substr(save, 0, i + (save[i] == '\n'));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save[FOPEN_MAX];
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX -1)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	save[fd] = read_line(fd, buffer, save[fd]);
	free(buffer);
	if (!save[fd])
		return (NULL);
	line = get_line(save[fd]);
	save[fd] = get_save(save[fd]);
	return (line);
}
