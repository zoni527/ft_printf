/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:32:18 by jvarila           #+#    #+#             */
/*   Updated: 2024/11/26 10:59:53 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

static int	print_ptr_val(uintptr_t ptr_val);

int	handle_p(const char **format_str_ptr, va_list ap)
{
	uintptr_t	ptr_val;
	int			counter;

	counter = 0;
	ptr_val = 0;
	ptr_val = (uintptr_t)va_arg(ap, void *);
	*format_str_ptr = ft_strchr(*format_str_ptr, 'p') + 1;
	if (!ptr_val)
		return (ft_putstr("(nil)"));
	counter += ft_putstr("0x");
	counter += print_ptr_val(ptr_val);
	return (counter);
}

static int	print_ptr_val(uintptr_t ptr_val)
{
	char		*hex_symbols;
	int			counter;
	uintptr_t	mod;
	char		c;

	counter = 0;
	hex_symbols = "0123456789abcdef";
	if (ptr_val >= 16)
		counter += print_ptr_val(ptr_val / 16);
	mod = ptr_val % 16;
	c = hex_symbols[mod];
	counter += ft_putchar(c);
	return (counter);
}
