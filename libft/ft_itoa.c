/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 17:52:08 by minckim           #+#    #+#             */
/*   Updated: 2020/04/06 17:54:01 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int n)
{
	char	digit[13];
	char	*tmp;
	char	*res;
	char	*res_o;
	int		sign;

	tmp = digit;
	*tmp++ = 0;
	if (n == 0)
		*tmp++ = '0';
	sign = n < 0 ? -1 : 1;
	while (n)
	{
		*tmp++ = n % 10 * sign + '0';
		n /= 10;
	}
	if (sign < 0)
		*tmp++ = '-';
	if (!(res = (char*)malloc(sizeof(char) * (tmp - digit))))
		return (0);
	res_o = res;
	while (*--tmp)
		*res++ = *tmp;
	*res = 0;
	return (res_o);
}
