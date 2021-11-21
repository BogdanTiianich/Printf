/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbecki <hbecki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 12:36:07 by hbecki            #+#    #+#             */
/*   Updated: 2021/11/21 17:38:36 by hbecki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	condition_set_1(va_list argptr, const char *init, int i)
{
	if (init[i + 1] == 'u')
	{
		return (ft_putnbr_fd_un(va_arg(argptr, unsigned int), 1));
	}
	if (init[i + 1] == 'p')
	{
		write(1, "0x", 2);
		return (hex_x_l(va_arg(argptr, unsigned long int), 1) + 2);
	}
	if (init[i + 1] == '%')
	{
		pr_perc();
		return (1);
	}
	if (init[i + 1] == 'c')
	{
		ft_putchar_fd(va_arg(argptr, int), 1);
		return (1);
	}
	return (0);
}

int	condition_set_2(va_list argptr, const char *init, int i)
{
	if (init[i + 1] == 's')
	{
		return (ft_putstr_fd(va_arg(argptr, char *), 1));
	}
	if (init[i + 1] == 'x')
	{
		return (hex_x(va_arg(argptr, unsigned int), 1));
	}
	if (init[i + 1] == 'X')
	{
		return (hex_big_x(va_arg(argptr, unsigned int), 1));
	}
	if (init[i + 1] == 'd' || init[i + 1] == 'i')
	{
		return (ft_putnbr_fd(va_arg(argptr, int), 1));
	}
	return (0);
}

int	ft_printf(const char *init, ...)
{
	int		i;
	int		counter;
	va_list	argptr;

	i = 0;
	counter = 0;
	va_start(argptr, init);
	while (init[i] != '\0')
	{
		if (init[i] == '%' && init[i + 1] != '\0')
		{
			counter = counter + condition_set_1(argptr, init, i);
			counter = counter + condition_set_2(argptr, init, i);
			i = i + 2;
		}
		else
		{
			write(1, &init[i], 1);
			counter++;
			i++;
		}
	}
	va_end(argptr);
	return (counter);
}
