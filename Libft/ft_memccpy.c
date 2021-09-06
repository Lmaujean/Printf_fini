/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:27:46 by lmaujean          #+#    #+#             */
/*   Updated: 2021/03/29 13:48:45 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)src)[i] == ((unsigned char)c))
		{
			(((unsigned char *)dst)[i] = ((unsigned char *)src)[i]);
			return (&(((unsigned char *)dst)[i + 1]));
		}	
		(((unsigned char *)dst)[i] = ((unsigned char *)src)[i]);
		i++;
	}
	return (NULL);
}
