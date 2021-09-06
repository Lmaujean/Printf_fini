/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 10:54:32 by lmaujean          #+#    #+#             */
/*   Updated: 2021/04/06 13:50:41 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		i++;
	}
	return (word);
}

static char	*strdupcpy(char *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	str = ft_calloc(sizeof(char), i + 1);
	if (!str)
		return (0);
	i = 0;
	while (*s != c && *s)
	{
		str[i] = *s;
		s++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**kherz;
	int		i;
	int		n;

	if (!s)
		return (0);
	n = count_word(s, c);
	kherz = ft_calloc(sizeof(char *), (count_word((char *)s, c) + 1));
	if (!kherz)
		return (0);
	i = 0;
	while (i < n)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
			kherz[i] = strdupcpy((char *)s, c);
		while (*s != c && *s)
			s++;
		i++;
	}
	return (kherz);
}
