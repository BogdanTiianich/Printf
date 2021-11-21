/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_vtor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbecki <hbecki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:49:01 by hbecki            #+#    #+#             */
/*   Updated: 2021/11/21 17:38:57 by hbecki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd_hex(unsigned int n, int i, int fd, int counter)
{
	char	c;

	if ((n / 16) * i > 0)
	{
		counter = ft_putnbr_fd_hex(n / 16, i, fd, 0);
	}
	counter++;
	c = (n % 16) * i + '0' * (1 - n % 16 / 10) + 'W' * (n % 16 / 10);
	write(fd, &c, 1);
	return (counter);
}

int	hex_x(unsigned int n, int fd)
{
	int	i;

	i = 1;
	if (n < 0)
		i = -1;
	return (ft_putnbr_fd_hex(n, i, fd, 0));
}

int	ft_putnbr_fd_hex_l(unsigned long int n, int i, int fd, int counter)
{
	char	c;

	if ((n / 16) * i > 0)
	{
		counter = ft_putnbr_fd_hex_l(n / 16, i, fd, 0);
	}
	c = (n % 16) * i + '0' * (1 - n % 16 / 10) + 'W' * (n % 16 / 10);
	counter++;
	write(fd, &c, 1);
	return (counter);
}

int	hex_x_l(unsigned long int n, int fd)
{
	int	i;

	i = 1;
	if (n < 0)
		i = -1;
	return (ft_putnbr_fd_hex_l(n, i, fd, 0));
}
