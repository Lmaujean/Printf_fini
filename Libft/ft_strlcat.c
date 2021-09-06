/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:33:03 by lmaujean          #+#    #+#             */
/*   Updated: 2021/03/29 14:17:44 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	j = ft_strlen(dst);
	n = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (!dstsize)
		return (ft_strlen(src));
	if (dstsize <= j)
		return (dstsize + n);
	while (i < dstsize - j - 1 && src[i])
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[i + j] = '\0';
	return (n + j);
}
