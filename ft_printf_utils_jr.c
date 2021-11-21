/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_jr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbecki <hbecki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:43:20 by hbecki            #+#    #+#             */
/*   Updated: 2021/11/21 17:39:01 by hbecki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd_helper(int n, int i, int fd, int counter)
{
	char	c;

	if ((n / 10) * i > 0)
	{
		counter = ft_putnbr_fd_helper(n / 10, i, fd, 0);
	}
	if ((i == -1) && !((n / 10) * i > 0))
	{
		counter++;
		c = '-';
		write(fd, &c, 1);
	}
	counter++;
	c = (n % 10) * i + '0';
	write(fd, &c, 1);
	return (counter);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	i;

	i = 1;
	if (n < 0)
		i = -1;
	return (ft_putnbr_fd_helper(n, i, fd, 0));
}

int	ft_putnbr_fd_hel_u(unsigned int n, int i, int fd, int counter)
{
	char	c;

	if ((n / 10) * i > 0)
	{
		counter = ft_putnbr_fd_hel_u(n / 10, i, fd, 0);
	}
	counter++;
	c = (n % 10) * i + '0';
	write(fd, &c, 1);
	return (counter);
}

int	ft_putnbr_fd_un(unsigned int n, int fd)
{
	int	i;

	i = 1;
	if (n < 0)
		i = -1;
	return (ft_putnbr_fd_hel_u(n, i, fd, 0));
}
