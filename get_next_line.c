/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaeho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:54:58 by idaeho            #+#    #+#             */
/*   Updated: 2019/05/16 20:27:32 by idaeho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strjoin2(char const *s1, char const *s2)
{
	char	*s3;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if (!(s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(s3, s1);
	ft_strcat(s3, s2);
	return (s3);
	return (NULL);
}

int		get_next_line(const int	fd, char **line)
{
	char			buf[BUFF_SIZE];
	static char		*s[MAX_FD];
	char			*track;
	int				sign;
	int				len;

	len = 0;
	if (fd > MAX_FD || fd < 0)
		return (-1);
	if (s[fd] == NULL)
		s[fd] = ft_strnew(1);
	while ((sign = read(fd, buf, BUFF_SIZE)) > 0)
	{
		printf("||%s||\n", s[fd]);
		buf[sign] = '\0';
		track = s[fd];
		s[fd] = ft_strjoin2(track, buf);
		free(track);
		if (strchr(buf, '\n'))
			break ;
	}

	printf("||%s||\n", s[fd]);
	*line = ft_strdup(s[fd]);
	return (0);
//	printf("%s\n", s[fd]);
	if (sign < 0)
		return (-1);
//	while (s[fd][len] != '\n')
//		len++;
	*line = strdup(s[fd]);
//	free(s[fd]);
	printf("line = %s\n", *line);
//	printf("sign = %d\n", sign);
	if (sign == 0)
		return (0);
	return (1);
}
