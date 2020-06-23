/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 17:59:12 by minckim           #+#    #+#             */
/*   Updated: 2020/04/06 18:00:43 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	digit[13];
	char	*tmp;
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
	while (*--tmp)
		write(fd, tmp, 1);
}
