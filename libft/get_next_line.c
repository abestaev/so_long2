/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:09:29 by albestae          #+#    #+#             */
/*   Updated: 2024/01/21 15:30:21 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_the_line(char **line, int end_line)
{
	char	*s;

	if (!*line || !**line)
	{
		if (*line)
		{
			free(*line);
			*line = (NULL);
		}
		return (NULL);
	}
	if (end_line == -1)
		end_line = ft_strlen_gnl(*line);
	s = ft_substr_free(*line, 0, end_line + 1, 0);
	*line = ft_substr_free(*line, end_line + 1, ft_strlen_gnl(*line), 1);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*line;
	int			end_line;
	int			result;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	end_line = ft_find_newline(line);
	if (end_line == -1)
		result = read(fd, buf, BUFFER_SIZE);
	while (end_line == -1 && result > 0)
	{
		buf[result] = '\0';
		line = ft_strjoin_free(line, buf);
		end_line = ft_find_newline(line);
		if (end_line == -1)
			result = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (get_the_line(&line, end_line));
}
