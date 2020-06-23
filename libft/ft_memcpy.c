/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 17:53:22 by minckim           #+#    #+#             */
/*   Updated: 2020/04/07 12:15:12 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;

	if (!dest && !src)
		return (0);
	dest_tmp = (unsigned char*)dest;
	src_tmp = (unsigned char*)src;
	while (n--)
		*dest_tmp++ = *src_tmp++;
	return (dest);
}
