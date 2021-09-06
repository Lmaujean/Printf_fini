/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:26:58 by lmaujean          #+#    #+#             */
/*   Updated: 2021/08/31 11:28:38 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_write_hexap(unsigned long long arg, int base, t_printf_env *env)
{
	char	tmp[21];
	int		i;
	int		j;

	i = 20;
	tmp[i--] = '\0';
	if (arg == 0)
		tmp[i--] = '0';
	while (arg)
	{
		j = arg % base;
		if (j > 9)
			tmp[i--] = j + 'a' - 10;
		else
			tmp[i--] = j + '0';
		arg /= base;
	}
	tmp[i--] = 'x';
	tmp[i--] = '0';
	ft_putstr_size(tmp + i + 1, 1, env);
}

void	*init_env(void)
{
	t_printf_env	*env;

	env = malloc(sizeof(t_printf_env));
	if (!env)
		ft_putstr_size("Malloc allocation failed", 1, env);
	return (env);
}

void	process_u_conv(int nb, t_printf_env *env)
{
	unsigned int	unsigned_nb;

	unsigned_nb = nb;
	ft_putnbr_unsigned(unsigned_nb, env);
}

void	process_x_conv(int nb, char conv, t_printf_env *env)
{
	char	*ret;
	int		i;

	ret = ft_itoa_base(nb, 16);
	i = -1;
	if (conv == 'x')
		while (ret[++i])
			ret[i] = ft_tolower(ret[i]);
	ft_putstr_size(ret, 1, env);
}

void	ft_putnbr_size(long long arg, int base, t_printf_env *env)
{
	if (arg < 0)
	{
		ft_putchar_size('-', base, env);
		arg = arg * -1;
	}
	if (arg > 9)
		ft_putnbr_size(arg / 10, base, env);
	arg = arg % 10 + '0';
	ft_putchar_size(arg, base, env);
}
