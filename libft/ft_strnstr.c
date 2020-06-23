/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 18:00:02 by minckim           #+#    #+#             */
/*   Updated: 2020/05/06 22:37:13 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n)
	{
		while (*s1 == *s2 && *s1 && *s2 && --n)
		{
			s1++;
			s2++;
		}
		return ((unsigned char)*s1 - (unsigned char)*s2);
	}
	else
		return (0);
}

char			*ft_strnstr(const char *big, const char *needle, size_t len)
{
	size_t	len_neddle;

	len_neddle = 0;
	while (*needle++)
		len_neddle++;
	needle -= len_neddle + 1;
	if (len_neddle == 0)
		return ((char*)big);
	if (len < len_neddle)
		return (0);
	len -= len_neddle - 1;
	while (*big && len--)
	{
		if (ft_strncmp(big++, needle, len_neddle) == 0)
			return ((char*)--big);
	}
	return ((char*)0);
}
