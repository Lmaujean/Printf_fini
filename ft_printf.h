/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:21:51 by lmaujean          #+#    #+#             */
/*   Updated: 2021/04/14 11:39:43 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "./Libft/libft.h"
# include <limits.h>

typedef struct s_printf_env
{
	int		read_size;
}				t_printf_env;

void		ft_write_hexap(unsigned long long arg, int base, t_printf_env *env);
void		*init_env(void);
void		process_u_conv(int nb, t_printf_env *env);
void		process_x_conv(int nb, char conv, t_printf_env *env);
void		ft_putnbr_unsigned(unsigned int n, t_printf_env *env);
char		*ft_itoa_base(int value, int base);
char		hex_digit(int v);
int			validate_data(const char *str);
int			get_size(long value, long base);
int			pro_conv(const char *str, int index, va_list ap, t_printf_env *env);
void		process_printing(va_list ap, const char *str, t_printf_env *env);
void		ft_putchar_size(char c, int fd, t_printf_env *env);
void		ft_putstr_size(char *str, int fd, t_printf_env *env);
void		ft_putnbr_size(long long arg, int base, t_printf_env *env);
int			ft_printf(const char *str, ...);

#endif