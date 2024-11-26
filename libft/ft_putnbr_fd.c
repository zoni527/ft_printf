/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:51:40 by jvarila           #+#    #+#             */
/*   Updated: 2024/11/12 12:48:52 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		counter;

	if (n == INT_MIN)
		return (write(1, "-2147483648", 11));
	counter = 0;
	if (n < 0)
	{
		counter += write(fd, "-", 1);
		return (counter + ft_putnbr_fd(-n, fd));
	}
	if (n >= 10)
		counter += ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	counter += write(fd, &c, 1);
	return (counter);
}
