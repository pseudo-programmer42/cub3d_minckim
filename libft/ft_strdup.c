/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 17:59:33 by minckim           #+#    #+#             */
/*   Updated: 2020/05/05 15:22:13 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*res;
	char	*c;

	len = 0;
	while (*s1++)
		len++;
	len++;
	s1 -= len;
	if (!(res = (char*)malloc(sizeof(char) * len)))
		return (0);
	c = res;
	while (*s1)
		*c++ = *s1++;
	*c = 0;
	return (res);
}
