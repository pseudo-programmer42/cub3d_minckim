/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 17:59:54 by minckim           #+#    #+#             */
/*   Updated: 2020/05/05 19:22:40 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;
	size_t			len;

	if (!s || !f)
		return (0);
	len = 0;
	while (*s++)
		len++;
	len++;
	s -= len;
	if (!(res = (char*)malloc(sizeof(char) * len)))
		return (0);
	i = 0;
	while (*s)
	{
		*(res + i) = f(i, *s++);
		i++;
	}
	*(res + i) = 0;
	return (res);
}
