/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaeho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 19:32:21 by idaeho            #+#    #+#             */
/*   Updated: 2019/05/16 20:14:01 by idaeho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*str;

	str = ft_strdup("am I here");
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		printf("%d\n",get_next_line(fd, &str));
		printf("no show = %s\n", str);
	}
	return (0);
}
