/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbecki <hbecki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:40:54 by hbecki            #+#    #+#             */
/*   Updated: 2021/11/21 17:38:42 by hbecki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int		i;

	if (s == NULL || fd < 0)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

void	pr_perc(void)
{
	int	i;

	i = 37;
	write(1, &i, 1);
}

int	ft_putnbr_fd_big_x(unsigned long int n, int i, int fd, int counter)
{
	char	c;

	if ((n / 16) * i > 0)
	{
		counter = ft_putnbr_fd_big_x(n / 16, i, fd, 0);
	}
	counter++;
	c = (n % 16) * i + '0' * (1 - n % 16 / 10) + '7' * (n % 16 / 10);
	write(fd, &c, 1);
	return (counter);
}

int	hex_big_x(unsigned long int n, int fd)
{
	int	i;

	i = 1;
	if (n < 0)
		i = -1;
	return (ft_putnbr_fd_big_x(n, i, fd, 0));
}
