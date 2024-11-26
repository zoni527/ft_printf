/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:33:44 by jvarila           #+#    #+#             */
/*   Updated: 2024/11/26 10:29:37 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

static int	handle_conversion(const char **format_str_ptr, va_list ap, char c);
static char	next_conversion_type(const char *format_str);

// Subfunctions advance the format string and return the amount of characters
// written in the absence of errors.
int	ft_printf(const char *format_str, ...)
{
	va_list	ap;
	int		counter;
	char	c;

	if (!format_str)
		return (-1);
	counter = 0;
	va_start(ap, format_str);
	counter += write_till_char(&format_str, '%');
	c = next_conversion_type(format_str);
	while (c)
	{
		counter += handle_conversion(&format_str, ap, c);
		counter += write_till_char(&format_str, '%');
		c = next_conversion_type(format_str);
	}
	va_end(ap);
	return (counter);
}

// In the case of an invalid format string conversion the format string position
// is advanced by two, skipping the percentage sign and the invalid specifier
// after it.
static int	handle_conversion(const char **format_str_ptr, va_list ap, char c)
{
	if (c == 'c')
		return (handle_c(format_str_ptr, ap));
	else if (c == 's')
		return (handle_s(format_str_ptr, ap));
	else if (c == 'p')
		return (handle_p(format_str_ptr, ap));
	else if (c == 'd')
		return (handle_d(format_str_ptr, ap));
	else if (c == 'i')
		return (handle_i(format_str_ptr, ap));
	else if (c == 'u')
		return (handle_u(format_str_ptr, ap));
	else if (c == 'x')
		return (handle_hex_lowercase(format_str_ptr, ap));
	else if (c == 'X')
		return (handle_hex_uppercase(format_str_ptr, ap));
	else if (c == '%')
		return (handle_percentage(format_str_ptr));
	else
		(*format_str_ptr) += 2;
	return (-1);
}

// The null character is returned if no valid conversion is found.
static char	next_conversion_type(const char *format_str)
{
	if (format_str)
		format_str = ft_strchr(format_str, '%');
	if (!format_str)
		return ('\0');
	if (ft_strchr(CONVERSION_SET, *(++format_str)))
		return (*format_str);
	return ('\0');
}
