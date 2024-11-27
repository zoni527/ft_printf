/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex_lowercase.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:32:18 by jvarila           #+#    #+#             */
/*   Updated: 2024/11/26 10:57:09 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

static int	print_hex(unsigned int hex);

int	handle_hex_lowercase(const char **format_str_ptr, va_list ap)
{
	unsigned int	hex;

	hex = 0;
	hex = va_arg(ap, unsigned int);
	*format_str_ptr = ft_strchr(*format_str_ptr, 'x') + 1;
	return (print_hex(hex));
}

static int	print_hex(unsigned int hex)
{
	char			*hex_symbols;
	int				rval;
	int				counter;
	unsigned int	mod;
	char			c;

	counter = 0;
	hex_symbols = "0123456789abcdef";
	if (hex >= 16)
	{
		rval = print_hex(hex / 16);
		if (rval < 0)
			return (-1);
		counter += rval;
	}
	mod = hex % 16;
	c = hex_symbols[mod];
	rval = ft_putchar(c);
	if (rval < 0)
		return (-1);
	counter += rval;
	return (counter);
}
