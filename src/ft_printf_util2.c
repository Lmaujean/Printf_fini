/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:33:23 by lmaujean          #+#    #+#             */
/*   Updated: 2021/08/31 11:33:27 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n, t_printf_env *env)
{
	if (n < 0)
		n *= -1;
	if (n > 9)
		ft_putnbr_unsigned(n / 10, env);
	n = n % 10 + '0';
	ft_putchar_size(n, 1, env);
}

char	*ft_itoa_base(int value, int base)
{
	char	*itoa;
	int		size;
	long	nb;

	nb = (long)value;
	if (nb < 0 && base != 10)
		nb = (unsigned int) nb;
	size = get_size(nb, (long)base);
	itoa = malloc(sizeof(char) * (size + 1));
	itoa[size--] = '\0';
	if (nb < 0 && base == 10)
	{
		itoa[0] = '-';
		nb = -nb;
	}
	while (size >= 0)
	{
		if (nb % (long)base > 9)
			itoa[size--] = '7' + nb % (long)base;
		else
			itoa[size--] = '0' + nb % (long)base;
		nb = nb / (long)base;
	}
	return (itoa);
}

char	hex_digit(int v)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else
		return ('a' + v - 10);
}

void	ft_putchar_size(char c, int fd, t_printf_env *env)
{
	write(fd, &c, 1);
	env->read_size += 1;
}

void	ft_putstr_size(char *str, int fd, t_printf_env *env)
{
	int	i;

	i = 0;
	if (str == NULL)
		str = "(null)";
	while (str[i])
	{	
		ft_putchar_size(str[i], fd, env);
		i++;
	}	
}
