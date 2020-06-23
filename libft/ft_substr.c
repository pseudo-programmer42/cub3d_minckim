/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 18:00:17 by minckim           #+#    #+#             */
/*   Updated: 2020/05/06 22:36:38 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (*s++)
		l++;
	return (l);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	char	*res_o;
	size_t	l;

	l = ft_strlen(s);
	if (!s)
		return (0);
	if (start > l)
	{
		res = (char*)malloc(sizeof(char));
		*res = 0;
		return (res);
	}
	l = l > start + len ? len + 1 : l - start + 1;
	if (!(res = (char*)malloc(sizeof(char) * l)))
		return (0);
	res_o = res;
	s += start;
	if (len)
		while (*s && len--)
		{
			*res++ = *s++;
		}
	*res = 0;
	return (res_o);
}
