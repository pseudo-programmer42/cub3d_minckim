/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 18:00:13 by minckim           #+#    #+#             */
/*   Updated: 2020/05/05 19:53:30 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_strdup(const char *s1)
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

static int	is_char_in(char c, const char *str)
{
	while (*str)
	{
		if (c == *str++)
			return (c);
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*res;
	char	*res_orig;

	if (!s1)
		return (0);
	while (is_char_in(*s1, set) && *s1)
		s1++;
	start = (char*)s1;
	if (!*start)
		return (ft_strdup(""));
	while (*s1)
		s1++;
	s1--;
	while (is_char_in(*s1, set) && s1 != start)
		s1--;
	end = (char*)s1;
	if (!(res = (char*)malloc(sizeof(char) * (end - start + 2))))
		return (0);
	res_orig = res;
	while (start != end + 1)
		*res++ = *start++;
	*res = 0;
	return (res_orig);
}
