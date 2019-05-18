/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaeho <idaeho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:54:58 by idaeho            #+#    #+#             */
/*   Updated: 2019/05/18 00:27:54 by idaeho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		end_read_line(int fd, char **s, char **line)
{
	char		*temp;

	if (s[fd][0] != '\0' && ft_strchr(s[fd], '\n') == 0)
	{
		*line = ft_strdup(s[fd]);
		temp = ft_strdup(s[fd] + ft_strlen(s[fd]));
		free(s[fd]);
		s[fd] = temp;
	}
	else if (s[fd][0] == '\0')
		return (0);
	return (1);
}

int		start_read_line(int fd, char **s, char **line)
{
	char		buf[BUFF_SIZE + 1];
	char		*track;
	int			sign;

	while ((sign = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		buf[sign] = '\0';
		track = s[fd];
		s[fd] = ft_strjoin(track, buf);
		free(track);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (sign < 0)
		return (-1);
	if (!s[fd])
		return (0);
	if (!end_read_line(fd, s, line))
		return (0);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*s[MAX_FD];
	int				len;
	int				check;
	char			*temp;

	len = 0;
	if (fd > MAX_FD || fd < 0 || !line)
		return (-1);
	if ((check = start_read_line(fd, s, line)) < 0)
		return (-1);
	else if (check == 0)
		return (0);
	if (ft_strchr(s[fd], '\n'))
		while (s[fd][len] != '\n')
			len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		temp = ft_strdup(s[fd] + len + 1);
		free(s[fd]);
		s[fd] = temp;
	}
	return (1);
}
