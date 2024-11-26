/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex_uppercase.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:32:18 by jvarila           #+#    #+#             */
/*   Updated: 2024/11/26 10:55:44 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

static int	print_hex(unsigned int hex);

int	handle_hex_uppercase(const char **format_str_ptr, va_list ap)
{
	unsigned int	hex;
	int				counter;

	counter = 0;
	hex = 0;
	hex = va_arg(ap, unsigned int);
	*format_str_ptr = ft_strchr(*format_str_ptr, 'X') + 1;
	counter += print_hex(hex);
	return (counter);
}

static int	print_hex(unsigned int hex)
{
	char			*hex_symbols;
	int				counter;
	unsigned int	mod;
	char			c;

	counter = 0;
	hex_symbols = "0123456789ABCDEF";
	if (hex >= 16)
		counter += print_hex(hex / 16);
	mod = hex % 16;
	c = hex_symbols[mod];
	counter += ft_putchar(c);
	return (counter);
}
