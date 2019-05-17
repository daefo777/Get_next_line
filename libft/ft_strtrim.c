/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaeho <idaeho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 22:04:35 by idaeho            #+#    #+#             */
/*   Updated: 2019/05/11 14:46:08 by idaeho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	size_t		start;
	size_t		end;

	if (!s)
		return (NULL);
	start = 0;
	while (ft_iswhitespace(s[start]))
		start++;
	end = ft_strlen(s);
	while (ft_iswhitespace(s[end - 1]))
		end--;
	if (end < start)
		end = start;
	return (ft_strsub(s, start, end - start));
}
