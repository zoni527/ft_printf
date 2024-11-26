/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_till_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:27:51 by jvarila           #+#    #+#             */
/*   Updated: 2024/11/26 11:00:55 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

// Function prints out every character that is not c and sets the format string
// to point to c (the percentage sign in the case of ft_printf). It returns the
// amount of written characters.
int	write_till_char(const char **format_str_ptr, char c)
{
	int	counter;

	counter = 0;
	while (**format_str_ptr && **format_str_ptr != c)
	{
		counter += ft_putchar(**format_str_ptr);
		(*format_str_ptr)++;
	}
	return (counter);
}
