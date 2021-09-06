/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:19:29 by lmaujean          #+#    #+#             */
/*   Updated: 2021/09/06 12:20:34 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	validate_data(const char *str)
{
	if (!str)
	{
		ft_putstr_fd("Format cannot be null", 1);
		return (-1);
	}
	return (0);
}

int	get_size(long value, long base)
{
	if (value > -base && value <= -1)
		return (2);
	if (value >= 0 && value < base)
		return (1);
	if (value < -base)
		return (2 + get_size(-value / base, base));
	return (1 + get_size(value / base, base));
}

int	pro_conv(const char *str, int index, va_list ap, t_printf_env *env)
{
	if (str[index + 1] == 'c')
		ft_putchar_size(va_arg(ap, int), 1, env);
	else if (str[index + 1] == 's')
		ft_putstr_size(va_arg(ap, char *), 1, env);
	else if (str[index + 1] == 'd' || str[index + 1] == 'i')
		ft_putnbr_size(va_arg(ap, int), 1, env);
	else if (str[index + 1] == 'u')
		process_u_conv(va_arg(ap, int), env);
	else if (str[index + 1] == '%')
		ft_putchar_size('%', 1, env);
	else if (str[index + 1] == 'x' || str[index + 1] == 'X')
		process_x_conv(va_arg(ap, int), str[index + 1], env);
	else if (str[index + 1] == 'p')
		ft_write_hexap(va_arg(ap, unsigned long), 16, env);
	return (index + 1);
}

void	process_printing(va_list ap, const char *str, t_printf_env *env)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
			i = process_conversion(str, i, ap, env);
		else
			ft_putchar_size(str[i], 1, env);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	t_printf_env	*env;
	int				valid;

	va_start(ap, str);
	env = init_env();
	if (!env)
		return (-1);
	valid = validate_data(str);
	if (valid < 0)
		return (-1);
	process_printing(ap, str, env);
	va_end(ap);
	return (env->read_size);
}
