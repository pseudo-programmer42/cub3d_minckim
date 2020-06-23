/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 17:53:17 by minckim           #+#    #+#             */
/*   Updated: 2020/04/07 12:15:12 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_tmp;
	unsigned char	*s2_tmp;

	s1_tmp = (unsigned char*)s1;
	s2_tmp = (unsigned char*)s2;
	if (!n)
		return (0);
	while (*s1_tmp == *s2_tmp && --n)
	{
		s1_tmp++;
		s2_tmp++;
	}
	return (*s1_tmp - *s2_tmp);
}
