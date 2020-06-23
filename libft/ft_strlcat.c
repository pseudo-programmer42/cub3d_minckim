/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 17:59:42 by minckim           #+#    #+#             */
/*   Updated: 2020/04/06 18:05:55 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*dst++)
		i++;
	if (dstsize > i)
	{
		dst--;
		dstsize -= i;
		while (*src && --dstsize)
		{
			*dst++ = *src++;
			i++;
		}
		*dst = 0;
		while (*src++)
			i++;
		return (i);
	}
	i = 0;
	while (*src++)
		i++;
	return (dstsize + i);
}
