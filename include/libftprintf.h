/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:22:00 by jvarila           #+#    #+#             */
/*   Updated: 2024/11/13 14:23:15 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>

# define CONVERSION_SET "cspdiuxX%"
# define HEX_BASE_LOWER "0123456789abcdef"
# define HEX_BASE_UPPER "0123456789ABCDEF"

int	ft_printf(const char *format_str, ...);
int	handle_c(const char **format_str_ptr, va_list ap);
int	handle_s(const char **format_str_ptr, va_list ap);
int	handle_p(const char **format_str_ptr, va_list ap);
int	handle_d(const char **format_str_ptr, va_list ap);
int	handle_i(const char **format_str_ptr, va_list ap);
int	handle_u(const char **format_str_ptr, va_list ap);
int	handle_hex_lowercase(const char **format_str_ptr, va_list ap);
int	handle_hex_uppercase(const char **format_str_ptr, va_list ap);
int	handle_percentage(const char **format_str_ptr);
int	write_till_char(const char **format_str_ptr, char c);

#endif
