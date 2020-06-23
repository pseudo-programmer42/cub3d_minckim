/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 17:59:23 by minckim           #+#    #+#             */
/*   Updated: 2020/05/05 19:54:39 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static char	**get_n_segment(const char *s, char c)
{
	size_t	count;
	char	**res;
	char	**res_o;

	count = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		count++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	if (!(res = (char**)malloc(sizeof(char*) * (count + 1))))
		return (0);
	res_o = res;
	while (count--)
		*res++ = (char*)1;
	*res = 0;
	return (res_o);
}

static char	*split_dup(char **d, const char *s, char c)
{
	size_t	len;
	char	*cursor;

	len = 0;
	while (*s != c && *s)
	{
		s++;
		len++;
	}
	s -= len;
	if (!(*d = (char*)malloc(sizeof(char) * (len + 1))))
	{
		return (0);
	}
	cursor = *d;
	while (*s != c && *s)
		*cursor++ = *s++;
	*cursor = 0;
	return ((char*)s);
}

static void	free_res(char **res)
{
	char **res_o;

	res_o = res;
	while (*res)
	{
		free(*res++);
	}
	free(res_o);
}

char		**ft_split(const char *s, char c)
{
	size_t	len;
	char	**res;

	if (!s)
		return (0);
	len = 0;
	if (!(res = get_n_segment(s, c)))
		return (0);
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (res[len])
			s = split_dup(res + len++, s, c);
		while (*s && *s == c)
			s++;
	}
	if (!s)
	{
		free_res(res);
		return (0);
	}
	return (res);
}
