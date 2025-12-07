/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outaouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 23:21:37 by outaouss          #+#    #+#             */
/*   Updated: 2025/12/07 23:21:39 by outaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_line(int fd, char *line)
{
	char	*buffer;
	ssize_t	read_bytes;

	buffer = (char *)malloc((long)BUFFER_SIZE + 1);
	if (!buffer)
	{
		printf("here\n");
		return (NULL);
	}
	read_bytes = 1;
	while (!ft_strchr(line, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buffer), NULL);
		buffer[read_bytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*ft_new_line(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = malloc(ft_strlen(line) - i + 1);
	if (!str)
	{
		free(line);
		return (NULL);
	}
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}

char	*ft_get_line(char *line)
{
	int		i;
	char	*str;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	str = malloc((i + (line[i] == '\n') + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line[FILE_D_MAX];
	char		*temp;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FILE_D_MAX)
		return (NULL);
	temp = ft_read_line(fd, line[fd]);
	if (!temp)
	{
		if (line[fd])
			free(line[fd]);
		line[fd] = NULL;
		return (NULL);
	}
	line[fd] = temp;
	next_line = ft_get_line(line[fd]);
	line[fd] = ft_new_line(line[fd]);
	return (next_line);
}
