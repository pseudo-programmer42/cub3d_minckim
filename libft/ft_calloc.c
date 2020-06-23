/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 07:29:43 by minckim           #+#    #+#             */
/*   Updated: 2020/04/06 17:58:35 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	void			*res;
	unsigned char	*res_o;

	i = count * size;
	if (!(res = malloc(i)))
		return (0);
	res_o = res;
	while (i--)
		*res_o++ = 0;
	return (res);
}
