/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:57:13 by lmaujean          #+#    #+#             */
/*   Updated: 2021/04/05 16:40:11 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_char(char const *set, char c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1 || !set)
		return (0);
	start = 0;
	while (find_char(set, s1[start]) && s1[start] != 0)
		start++;
	end = ft_strlen(s1);
	while (find_char(set, s1[end - 1]) && end > start)
		end--;
	str = malloc(sizeof(char) * (end - start) + 1);
	if (!str)
		return (0);
	i = 0;
	while (end > start)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
