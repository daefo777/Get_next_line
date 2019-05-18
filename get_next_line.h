/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaeho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 16:33:10 by idaeho            #+#    #+#             */
/*   Updated: 2019/05/18 00:15:37 by idaeho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define MAX_FD 4864
# define BUFF_SIZE 8

# include <unistd.h>
# include <stdlib.h>
# include "./libft/includes/libft.h"

int		get_next_line(const int fd, char **line);
int		start_read_line(int fd, char **s, char **line);

#endif
