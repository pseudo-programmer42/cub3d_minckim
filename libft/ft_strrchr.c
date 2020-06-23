/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 18:00:08 by minckim           #+#    #+#             */
/*   Updated: 2020/04/07 22:41:13 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*r;

	c = (char)c;
	r = 0;
	while (1)
	{
		if (*s == c)
			r = (char*)s;
		if (!*s)
			return (r);
		s++;
	}
	return (r);
}
