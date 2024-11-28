/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:32:18 by jvarila           #+#    #+#             */
/*   Updated: 2024/11/26 10:50:23 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

static int	ft_putnbr_u(unsigned int u);

int	handle_u(const char **format_str_ptr, va_list ap)
{
	unsigned int	u;
	char			*u_str;

	u = va_arg(ap, unsigned int);
	*format_str_ptr = ft_strchr(*format_str_ptr, 'u') + 1;
	u_str = ft_utoa(u);
	return (ft_putnbr_u(u));
}

static int	ft_putnbr_u(unsigned int u)
{
	int				counter;
	unsigned int	mod;
	char			c;

	counter = 0;
	if (u >= 10)
		counter += ft_putnbr_u(u / 10);
	mod = u % 10;
	c = '0' + mod;
	counter += ft_putchar(c);
	return (counter);
}
