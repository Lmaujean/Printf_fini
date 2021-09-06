/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:19:10 by lmaujean          #+#    #+#             */
/*   Updated: 2021/04/14 11:35:11 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_char(int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			symbole;
	int			i;
	char		*str;

	symbole = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		symbole++;
	}
	i = count_char(n) + symbole;
	str = ft_calloc(sizeof(char), i + 1);
	if (str == 0)
		return (0);
	while (i > 0)
	{
		i--;
		str[i] = n % 10 + 48;
		n = n / 10;
	}
	if (symbole == 1)
		str[i] = '-';
	return (str);
}
