/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:32:50 by lmaujean          #+#    #+#             */
/*   Updated: 2021/04/14 11:38:45 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	if (len < ft_strlen(s))
		str = ft_calloc(sizeof(char), len + 1);
	else
		str = ft_calloc(sizeof(char), (ft_strlen(s + start) + 1));
	if (!str)
		return (0);
	if (start < ft_strlen(s))
	{
		i = 0;
		while (i < len && s[start])
		{
			str[i] = s[start];
			i++;
			start++;
		}
	}	
	return (str);
}
