/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaeho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 19:32:21 by idaeho            #+#    #+#             */
/*   Updated: 2019/05/16 18:56:20 by idaeho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;
//	int		save;
//	char	buf[10];

	if (argc == 2)
	{
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[1], O_RDONLY);
//		save = read(fd1, buf, 10);
		printf("%d", save);
		while (get_next_line(fd1, &line1))
			printf("%s\n", line1);
		while (get_next_line(fd2, &line2))
			printf("%s\n", line2);
	}
	return (0);
}
