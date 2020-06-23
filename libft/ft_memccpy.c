/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 17:53:07 by minckim           #+#    #+#             */
/*   Updated: 2020/04/07 12:15:12 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;
	unsigned char	c_tmp;

	if (!dest && !src)
		return (0);
	dest_tmp = (unsigned char*)dest;
	src_tmp = (unsigned char*)src;
	c_tmp = (unsigned char)c;
	while (n--)
	{
		*dest_tmp++ = *src_tmp;
		if (*src_tmp++ == c_tmp)
			return (dest_tmp);
	}
	return (0);
}
