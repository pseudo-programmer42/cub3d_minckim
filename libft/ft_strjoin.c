/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 17:59:38 by minckim           #+#    #+#             */
/*   Updated: 2020/05/05 19:51:13 by minckim          ###   ########.fr       */
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

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ln;
	char	*res;
	char	*res_o;

	if (!s1 || !s2)
		return (0);
	ln = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(res = (char*)malloc(sizeof(char) * ln)))
		return (0);
	res_o = res;
	while (*s1)
		*res++ = *s1++;
	while (*s2)
		*res++ = *s2++;
	*res = 0;
	return (res_o);
}
